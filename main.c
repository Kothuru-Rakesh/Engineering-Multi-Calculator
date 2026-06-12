#include <stdio.h>
#include <math.h>

double lastResult = 0;

// Function declarations
void electrical();
void fluid();
void mechanical();
void conversion();
void materialDatabase();

void electrical() {
    int ch;
    double V,I,R,P,R1,R2;

    do {
        printf("\n--- ELECTRICAL MODULE ---\n");
        printf("1. Ohm's Law\n2. Power\n3. Series Resistance\n4. Parallel Resistance\n5. Back\n");
        scanf("%d",&ch);

        switch(ch) {
            case 1:
                printf("Enter Voltage(V): ");
                scanf("%lf",&V);
                printf("Enter Current(I): ");
                scanf("%lf",&I);
                R = V/I;
                lastResult = R;
                printf("Resistance = %.2lf Ohms\n",R);
                break;

            case 2:
                printf("Enter Voltage(V): ");
                scanf("%lf",&V);
                printf("Enter Current(I): ");
                scanf("%lf",&I);
                P = V*I;
                lastResult = P;
                printf("Power = %.2lf Watts\n",P);
                break;

            case 3:
                printf("Enter R1 and R2: ");
                scanf("%lf%lf",&R1,&R2);
                R = R1 + R2;
                lastResult = R;
                printf("Series Resistance = %.2lf Ohms\n",R);
                break;

            case 4:
                printf("Enter R1 and R2: ");
                scanf("%lf%lf",&R1,&R2);
                R = (R1*R2)/(R1+R2);
                lastResult = R;
                printf("Parallel Resistance = %.2lf Ohms\n",R);
                break;
        }

    } while(ch!=5);
}

void fluid() {
    int ch,mat;
    double rho,g=9.81,h,P,A,v,Q,D,mu,Re,V,Fb,L,f,hf,F1,A1,A2,F2;

    do {
        printf("\n--- FLUID MECHANICS ---\n");
        printf("1.Hydrostatic Pressure\n");
        printf("2.Density\n");
        printf("3.Flow Rate\n");
        printf("4.Continuity Equation\n");
        printf("5.Reynolds Number\n");
        printf("6.Buoyant Force\n");
        printf("7.Pipe Head Loss\n");
        printf("8.Hydraulic Force\n");
        printf("9.Back\n");
        scanf("%d",&ch);

        switch(ch) {

            case 1:
                printf("Material:\n1.Water\n2.Oil\n3.Mercury\n");
                scanf("%d",&mat);

                if(mat==1) rho=1000;
                else if(mat==2) rho=900;
                else rho=13600;

                printf("Enter depth(h): ");
                scanf("%lf",&h);

                P=rho*g*h;
                lastResult=P;
                printf("Pressure = %.2lf Pa\n",P);
                break;

            case 2:
                double m,Vv;
                printf("Enter Mass and Volume: ");
                scanf("%lf%lf",&m,&Vv);
                rho=m/Vv;
                lastResult=rho;
                printf("Density = %.2lf kg/m^3\n",rho);
                break;

            case 3:
                printf("Enter Area and Velocity: ");
                scanf("%lf%lf",&A,&v);
                Q=A*v;
                lastResult=Q;
                printf("Flow Rate = %.2lf m^3/s\n",Q);
                break;

            case 4:
                double A1v,V1,A2v,V2;
                printf("Enter A1,V1,A2: ");
                scanf("%lf%lf%lf",&A1v,&V1,&A2v);
                V2=(A1v*V1)/A2v;
                lastResult=V2;
                printf("Velocity V2 = %.2lf m/s\n",V2);
                break;

            case 5:
                printf("Enter Density, Velocity, Diameter, Viscosity: ");
                scanf("%lf%lf%lf%lf",&rho,&v,&D,&mu);
                Re=(rho*v*D)/mu;
                lastResult=Re;
                printf("Reynolds Number = %.2lf\n",Re);
                break;

            case 6:
                printf("Enter Density and Volume displaced: ");
                scanf("%lf%lf",&rho,&V);
                Fb=rho*g*V;
                lastResult=Fb;
                printf("Buoyant Force = %.2lf N\n",Fb);
                break;

            case 7:
                printf("Enter friction factor, length, diameter, velocity: ");
                scanf("%lf%lf%lf%lf",&f,&L,&D,&v);
                hf=f*(L/D)*(v*v/(2*g));
                lastResult=hf;
                printf("Head Loss = %.2lf m\n",hf);
                break;

            case 8:
                printf("Enter F1,A1,A2: ");
                scanf("%lf%lf%lf",&F1,&A1,&A2);
                F2=(F1*A2)/A1;
                lastResult=F2;
                printf("Hydraulic Output Force = %.2lf N\n",F2);
                break;
        }

    } while(ch!=9);
}

void mechanical() {
    int ch;
    double F,A,sigma,r,P,v,a,u,t;

    do {
        printf("\n--- MECHANICAL MODULE ---\n");
        printf("1.Stress\n2.Torque\n3.Power\n4.Velocity\n5.Acceleration\n6.Back\n");
        scanf("%d",&ch);

        switch(ch) {

            case 1:
                printf("Enter Force and Area: ");
                scanf("%lf%lf",&F,&A);
                sigma=F/A;
                lastResult=sigma;
                printf("Stress = %.2lf Pa\n",sigma);
                break;

            case 2:
                printf("Enter Force and Radius: ");
                scanf("%lf%lf",&F,&r);
                lastResult=F*r;
                printf("Torque = %.2lf Nm\n",lastResult);
                break;

            case 3:
                printf("Enter Force and Velocity: ");
                scanf("%lf%lf",&F,&v);
                P=F*v;
                lastResult=P;
                printf("Mechanical Power = %.2lf W\n",P);
                break;

            case 4:
                printf("Enter Distance and Time: ");
                scanf("%lf%lf",&u,&t);
                lastResult=u/t;
                printf("Velocity = %.2lf m/s\n",lastResult);
                break;

            case 5:
                printf("Enter Velocity and Time: ");
                scanf("%lf%lf",&v,&t);
                a=v/t;
                lastResult=a;
                printf("Acceleration = %.2lf m/s^2\n",a);
                break;
        }

    } while(ch!=6);
}

void conversion() {
    int ch;
    double x;

    do {
        printf("\n--- UNIT CONVERSION ---\n");
        printf("1.mm to cm\n");
        printf("2.m to km\n");
        printf("3.C to F\n");
        printf("4.Pa to kPa\n");
        printf("5.m/s to km/h\n");
        printf("6.Back\n");
        scanf("%d",&ch);

        switch(ch) {

            case 1:
                scanf("%lf",&x);
                printf("%.2lf cm\n",x/10);
                break;

            case 2:
                scanf("%lf",&x);
                printf("%.2lf km\n",x/1000);
                break;

            case 3:
                scanf("%lf",&x);
                printf("%.2lf F\n",(x*9/5)+32);
                break;

            case 4:
                scanf("%lf",&x);
                printf("%.2lf kPa\n",x/1000);
                break;

            case 5:
                scanf("%lf",&x);
                printf("%.2lf km/h\n",x*3.6);
                break;
        }

    } while(ch!=6);
}

int main() {

    int choice;

    do {
        printf("\n====================================\n");
        printf(" ENGINEERING SMART CALCULATOR\n");
        printf("====================================\n");
        printf("Last Result = %.2lf\n",lastResult);

        printf("\n1.Electrical\n");
        printf("2.Fluid Mechanics\n");
        printf("3.Mechanical\n");
        printf("4.Unit Conversion\n");
        printf("5.Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                electrical();
                break;
            case 2:
                fluid();
                break;
            case 3:
                mechanical();
                break;
            case 4:
                conversion();
                break;
            case 5:
                printf("Thank You!\n");
                break;
            default:
                printf("Invalid Choice\n");
        }

    } while(choice!=5);

    return 0;
}
