#include <iostream>
#include <math.h>

#define PI 3.1416

using namespace std;


class complexNumber{
private:
    double X, Y, mod;
public:
    complexNumber(double X = 0, double Y = 0){
        this->X = X;
        this->Y = Y;
        this->mod = sqrt((X*X)+(Y*Y));
    }
    complexNumber(const complexNumber &c){
        this->X = c.X;
        this->Y = c.Y;
        this->mod = c.mod;
    }
    complexNumber &operator+=(const complexNumber& m){
        this->X += m.X;
        this->Y += m.Y;
        return *this;
    }
    complexNumber &operator+=(const double& m){
        this->X += m;
        this->Y += m;
        return *this;
    }
    complexNumber &operator-=(const complexNumber& m){
        this->X -= m.X;
        this->Y -= m.Y;
        return *this;
    }
    complexNumber &operator-=(const double& m){
        this->X -= m;
        this->Y -= m;
        return *this;
    }
    complexNumber &operator*=(const complexNumber& m){
        double t1, t2;
        t1 = ((this->X)*(m.X))-((this->Y)*(m.Y));
        t2 = ((this->X)*(m.Y))+((this->Y)*(m.X));
        this->X = t1;
        this->Y = t2;
        return *this;
    }
    complexNumber &operator*=(const double& m){
        this->X *= m;
        this->Y *= m;
        return *this;
    }
    complexNumber &operator/=(const complexNumber& m){
        if (m.X!=0 && m.Y!=0){
            double t1, t2;
            t1 = ((this->X)*(m.X)+((this->Y)*(m.Y)))/(pow(m.X, 2)-pow(m.Y, 2));
            t2 = (-(this->X)*(m.Y)+((this->Y)*(m.X)))/(pow(m.X, 2)-pow(m.Y, 2));
            this->X = t1;
            this->Y = t2;
        }
        return *this;
    }
    complexNumber &operator/=(const double& m){
        if (m!=0){
            this->X /= m;
            this->Y /= m;
        }
        return *this;
    }

    bool operator==(const complexNumber &n){
        return (( this->X == n.X ) && ( this->Y == n.Y ) );
    }
    bool operator!=(const complexNumber &n){
        return !(( this->X == n.X ) && ( this->Y == n.Y ) );
    }
    bool operator>=(const complexNumber &n){
        return (( this->X >= n.X ) && ( this->Y >= n.Y ) );
    }
    bool operator<=(const complexNumber &n){
        return (( this->X <= n.X ) && ( this->Y <= n.Y ) );
    }
    bool operator>(const complexNumber &n){
        return (( this->X > n.X ) && ( this->Y > n.Y ) );
    }
    bool operator<(const complexNumber &n){
        return (( this->X < n.X ) && ( this->Y < n.Y ) );
    }

    friend ostream & operator<<(ostream &out, complexNumber &s){
        out << "X: " << s.GetX() << " Y: " << s.GetY();
        s.SetModule();
        out << " module: " << s.GetModule() << "\n";
        return out;
    }
    friend istream & operator>>(istream &in, complexNumber &s){
        cout << "X: ";
        in >> s.X;
        cout << "Y: ";
        in >> s.Y;
        return in;
    }

    complexNumber &operator^(const double& power){
        double module = this->GetModule();
        double angle = atan(this->Y/this->X);
        this->X = pow(module, power)*cos(power*angle);
        this->Y = pow(module, power)*sin(power*angle);
        return *this;
    }

    void SetX(double X){
        this->X = X;
        SetModule();
    }
    void SetY(double Y){
        this->Y = Y;
        SetModule();
    }
    void SetModule(){
        this->mod = sqrt((X*X)+(Y*Y));
    }
    double GetX(){
        return this->X;
    }
    double GetY(){
        return this->Y;
    }
    double GetModule(){
        return this->mod;
    }
};