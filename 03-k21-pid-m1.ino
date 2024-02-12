#define ENCOA1 3
#define R_PWM1 6
#define L_PWM1 7

float maxpulse = 133;
int pulse1 = 0;
float pulse1_pos = 0;

int interval1 = 100;
unsigned int waktulama1, waktusekarang1;
int rpm1;

float Kp1 = 0.039; //0.65;
float Ki1 = 0.26;//0.4;
float Kd1 = 0.0014625; //0.00225;

float setPointRpm1 = 3000;
int error1;
int prevError1; // integral error
int integral1;
int derivative1;

int MV1 = 0; // manipulated variabel nilai kalkulasi pid
float motorV1 = 0;
int motor1Pwm = 0;
int dir_m1;

//Kinematika Motor 1
int dir1;
float rpm_m1 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ENCOA1, INPUT_PULLUP);
  pinMode(R_PWM1, OUTPUT);
  pinMode(L_PWM1, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(ENCOA1), encoder1, RISING);
  delay(100);
}

void loop() {
  kinematics(0, -150, 0);
  PIDrpm1(rpm_m1, dir1);

}
