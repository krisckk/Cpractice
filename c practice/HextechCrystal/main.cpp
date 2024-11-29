#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
class Function {
    public:
        static Function *parse(stringstream &ss);
        virtual Function *differential() = 0;
        virtual double eval(double) = 0;
};
class Constant : public Function
{
	public:
	static Constant *create(const double &val){
		return new Constant{val};
	}
	Function *differential() override{
		return new Constant{0};
	}
	double eval(double) override{
		return val;
	}
	private:
	Constant(const double &val) : val{val}{}
	double val;
};

class Variable : public Function
{
	public:
	static Variable *create(string &name){
		return new Variable{name};
	}
	Function *differential() override{
		return Constant::create(1);
	}
	double eval(double val) override{
		return val;
	}
	private:
	Variable(string &name) : name{name}{}
	string name;
};

class Polynomial : public Function
{
	public:
	static Polynomial *create(Function *_base, Function *_exp){
		return new Polynomial(_base, _exp);
	}
	Function *differential() override; // implement later
	double eval(double val) override{
		return pow(base -> eval(val), exp -> eval(val));
	}
	private:
	Polynomial(Function *base, Function *exp) : base{base}, exp{exp} {}
	Function *base;
	Function *exp;
};

class Arithmetic : public Function
{
	public:
	static Arithmetic *create(Function *_lhs, char op, Function *_rhs){
		switch(op){
			case '+':
				return new Arithmetic(Type::ADD, _lhs, _rhs);
			case '-':
				return new Arithmetic(Type::SUB, _lhs, _rhs);
			case '*':
				return new Arithmetic(Type::MUL, _lhs, _rhs);
			case '/':
				return new Arithmetic(Type::DIV, _lhs, _rhs);
		}
	}
	Function *differential() override{
		Function *lhs_diff = lhs -> differential();
		Function *rhs_diff = rhs -> differential();
		switch(type){
			case Type::ADD:
			case Type::SUB:
				return new Arithmetic(type, lhs_diff, rhs_diff);
			case Type::MUL:
				return new Arithmetic{
					Type::ADD,
					new Arithmetic{Type::MUL, lhs_diff, rhs},
					new Arithmetic{Type::MUL, lhs, rhs_diff}
				};
			case Type::DIV:
				return new Arithmetic{
					Type::DIV,
					new Arithmetic{
						Type::SUB,
						new Arithmetic{Type::MUL, lhs_diff, rhs},
						new Arithmetic{Type::MUL, lhs, rhs_diff}
					},
					new Arithmetic{Type::MUL, rhs, rhs}
				};
		}
	}
	double eval(double val) override{
		switch(type){
			case Type::ADD:
				return lhs -> eval(val) + rhs -> eval(val);
			case Type::SUB:
				return lhs -> eval(val) - rhs -> eval(val);
			case Type::MUL:
				return lhs -> eval(val) * rhs -> eval(val);
			case Type::DIV:
				return lhs -> eval(val) / rhs -> eval(val);
		}
	}
	private:
	enum class Type {ADD, SUB, MUL, DIV};
	Arithmetic(Type _type, Function *_lhs, Function *_rhs) : type{_type}, lhs{_lhs}, rhs{_rhs}{}
	Type type;
	Function *lhs, *rhs;
};

class Sin : public Function
{
	public:
	static Sin *create(Function *_base){
		return new Sin{_base};
	}
	Function *differential() override;// implement later
	double eval(double val) override{
		return sin(base -> eval(val));
	}
	private:
	Sin(Function *_base) : base{_base}{}
	Function *base;
};

class Cos : public Function
{
	public:
	static Cos *create(Function *_base){
		return new Cos{_base};
	}
	Function *differential() override{
		return Arithmetic::create(Constant::create(0), '-', Arithmetic::create(Sin::create(base), '*', base -> differential()));
	}
	double eval(double val) override{
		return cos(base -> eval(val));
	}
	private:
	Cos(Function *_base) : base{_base}{}
	Function *base;
};
Function *Polynomial::differential(){
	return Arithmetic::create(
		exp,
		'*',
		Arithmetic::create(
			new Polynomial{
				base, Constant::create(exp -> eval(0) - 1)
			},
			'*',
			base -> differential()
		)
	);
}
Function *Sin::differential(){
	return Arithmetic::create(
		Cos::create(base),
		'*',
		base -> differential()
	);
}
