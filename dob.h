#ifndef DOB_H
#define DOB_H

#include "matrix.h"
#include <time.h>
#include <QElapsedTimer>

class Body
{
public:
    Body();
    // base body information
    Matrix A0, C01;
    Vector s01p;
    // body initial data
    double qi, qi_dot, m;
    Vector ri, ri_dot, wi, rhoip, sijp;
    Matrix Jip, Cii, Cij;
    // Orientation
    Matrix Aijpp, Ai;
    Vector Hi, u_vec;
    // Position
    Vector sij, rhoi, ric;
    Matrix rit;
    // Velocity State
    Vector Bi, Yih;
    // Cartesian velocity state
    Matrix Ti, wit;
    Vector Yib, ric_dot;
    // Mass & Force
    Matrix Jic, rict, rict_dot, Mih;
    Vector Fic, Tic, Qih;
    // Velocity Coupling
    Matrix rit_dot;
    Vector dHi, Di;
    // System EQM
    Matrix Ki;
    Vector Li;
    // Acceleration
    double qi_ddot;
    // Generalized Force(Torque)
    double Q;
    // Gravity force
    Vector Fg;
    double Tg;
    // Control
    double des_vel, err_vel, err_vel_accum, err_vel_prev, T_control, T_control_vel, Kp_vel, Ki_vel, Kd_vel;
    // Residual
    double r_hat, K, p, Ta, Td, yp;
};

inline Body::Body(){
    u_vec << 0,0,1;

    // base body information
    A0 = Matrix(3,3);
    C01 = Matrix(3,3);
    s01p = Vector(3);
    // body initial data
    qi = 0;
    qi_dot = 0;
    qi_ddot = 0;
    ri = Vector(3);
    ri_dot = Vector(3);
    wi = Vector(3);
    rhoip = Vector(3);
    sijp = Vector(3);
    Jip = Matrix(3, 3);
    Cii = Matrix(3, 3);
    Cij = Matrix(3, 3);
    // Orientation
    Aijpp = Matrix(3, 3);
    Ai = Matrix(3, 3);
    Hi = Vector(3);
    u_vec = Vector(3);
    // Position
    sij = Vector(3);
    rhoi = Vector(3);
    ric = Vector(3);
    rit = Matrix(3, 3);
    // Velocity State
    Bi = Vector(6);
    Yih = Vector(6);
    // Cartesian velocity state
    Ti = Matrix(6, 6);
    wit = Matrix(3, 3);
    Yib = Vector(6);
    ric_dot = Vector(3);
    // Mass & Force
    Jic = Matrix(3, 3);
    rict = Matrix(3, 3);
    rict_dot = Matrix(3, 3);
    Mih = Matrix(6, 6);
    Fic = Vector(3);
    Tic = Vector(3);
    Qih = Vector(6);
    // Velocity Coupling
    rit_dot = Matrix(3, 3);
    dHi = Vector(3);
    Di = Vector(6);
    // System EQM
    Ki = Matrix(6, 6);
    Li = Vector(6);
    // Generalized Force(Torque)
    Q = 0;
    // Gravity force
    Fg = Vector(6);
    Tg = 0;
    // Residual
    r_hat = 0;
    K = 0;
    p = 0;
    Ta = 0;
    Td = 0;
    yp = 0;
}

class DOB
{
public:
    DOB(uint num_body);
    ~DOB();
    void run();
    double total_time, average_time;
private:
    uint num_body;
    Body* body;

    double start_time, end_time, h, g, t_current;

    Vector Y, Yp, Y_old, Yp_old;

    void analysis();
        void Y2qdq();
        void kinematics_analysis();
        void generalized_mass_force();
        void residual_analysis();
        void dynamics_analysis();
            Matrix ludcmp(Matrix a, uint* indx);
            Vector lubksb(Matrix fac, uint* indx, Vector b);
        void dqddq2Yp();
};

#endif // DOB_H
