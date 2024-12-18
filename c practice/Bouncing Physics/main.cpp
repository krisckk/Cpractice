#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class Object {
public:
    Object(double W) : weight{W}, vx{0}, vy{0}, x{0}, y{0}, r{0} {}
    void setCircle(double X, double Y, double R) {
        x = X, y = Y, r = R;
    }
    void setSpeed(double Vx, double Vy) {
        vx = Vx, vy = Vy;
    }
    double &getSpeedX() { return vx; }
    double &getSpeedY() { return vy; }
    double &getX() { return x; }
    double &getY() { return y; }
    double &getR() { return r; }
    const double &getWeight() const { return weight; }
    const double &getSpeedX() const { return vx; }
    const double &getSpeedY() const { return vy; }
    double getVelocity() const { return sqrt(vx * vx + vy * vy); }
    double getAngle() const { return atan2(vy, vx) * 180.0 / M_PI; }
    const double &getX() const { return x; }
    const double &getY() const { return y; }
    const double &getR() const { return r; }
private:
    double weight;
    double vx, vy;
    double x, y, r;
};
class PhysicEngine {
    private:
        double G = 9.8;
        unsigned int fps;
        vector<Object> objects;
    public:
        PhysicEngine() : fps(60) {}
        void SetFPS(unsigned int FPS) {
            fps = FPS;
        }
        unsigned int getFPS() {
            return fps;
        }
        void addObject(const Object &object) {
            objects.emplace_back(object);
        }
        const vector<Object> &getObjects() const {
            return objects;
        }
        void reset() {
            objects.clear();
        }
        void update(){
            double dt = 1.0 / getFPS();
            for(Object &object : objects){
                object.getSpeedY() -= G * dt;
                object.getX() += object.getSpeedX() * dt;
                object.getY() += object.getSpeedY() * dt;
            }
            for(size_t i = 0; i < objects.size(); ++i){
                Object &obj1 = objects[i];
                for(size_t j = i + 1; j < objects.size(); ++j){
                    Object &obj2 = objects[j];
                    double dx = obj1.getX() - obj2.getX();
                    double dy = obj1.getY() - obj2.getY();
                    double dr = obj1.getR() + obj2.getR();
                    if(dx * dx + dy * dy < dr * dr){
                        auto translate = [](double &x, double &y, double sin_theta, double cos_theta){
                            auto [_x, _y] = make_pair(x * cos_theta + y * sin_theta, -x * sin_theta + y * cos_theta);
                            x = _x, y = _y;
                        };
                        double x1 = obj1.getX(), y1 = obj1.getY();
                        double x2 = obj2.getX(), y2 = obj2.getY();
                        double vx1 = obj1.getSpeedX(), vy1 = obj1.getSpeedY();
                        double vx2 = obj2.getSpeedX(), vy2 = obj2.getSpeedY();
                        double m1 = obj1.getWeight(), m2 = obj2.getWeight();
                        double cos_theta = dx / sqrt(dx * dx + dy * dy);
                        double sin_theta = dy / sqrt(dx * dx + dy * dy);
                        translate(x1, y1, sin_theta, cos_theta);
                        translate(x2, y2, sin_theta, cos_theta);
                        translate(vx1, vy1, sin_theta, cos_theta);
                        translate(vx2, vy2, sin_theta, cos_theta);
                        // 1D elastic collision: only afgfects x-axis                   
                        double ux1 = (vx1 * (m1 - m2) + 2 * m2 * vx2) / (m1 + m2);
                        double uy1 = vy1;
                        double ux2 = (vx2 * (m2 - m1) + 2 * m1 * vx1) / (m1 + m2);
                        double uy2 = vy2;
                        // Translate back
                        translate(ux1, uy1, -sin_theta, cos_theta);
                        translate(ux2, uy2, -sin_theta, cos_theta);
                        obj1.setSpeed(ux1, uy1);
                        obj2.setSpeed(ux2, uy2);
                        // Fix overlap
                        double d = sqrt(dx * dx + dy * dy);
                        double overlap = dr - d;
                        double overlapX = overlap * dx / d;
                        double overlapY = overlap * dy / d;
                        obj1.getX() += overlapX / 2;
                        obj1.getY() += overlapY / 2;
                        obj2.getX() -= overlapX / 2;
                        obj2.getY() -= overlapY / 2;
                    }
                }
            }
            for(Object &object : objects) {
                if(object.getY() - object.getR() <= 0) {
                    object.getSpeedY() = abs(object.getSpeedY());
                }
            }
        }
};
