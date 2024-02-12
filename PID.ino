void PIDrpm1(int targetVel1, int dir_m1) { // fungsi PID rpm
  waktusekarang1 = millis(); 
  if (waktusekarang1 - waktulama1 >= interval1) {
    rpm1 = (pulse1 / maxpulse) * 600; 
    error1   = abs(targetVel1) - abs(rpm1); // perhitungan PID sampe MV
    integral1 += error1;
    derivative1 = (error1 - prevError1);
    
    MV1 = (Kp1 * error1) + (Ki1 * integral1) + (Kd1 * derivative1);
    prevError1 = error1;
    
    motorV1 = abs((float(MV1) / 490) * 255);
    motor1Pwm = int(motorV1);
    
    if (dir_m1 == 1) {
      analogWrite(R_PWM1, motorV1);
      analogWrite(L_PWM1, 0);
    }

    else if (dir_m1 == -1) {
      analogWrite(R_PWM1, 0);
      analogWrite(L_PWM1, motorV1);
    }
    else {
      analogWrite(R_PWM1, 0);
      analogWrite(L_PWM1, 0);
    }

    Serial.print(" Nilai Kecepatan1 : ");
    Serial.println(rpm1);
    Serial.print("Setpoint 1 : ");
    Serial.println(targetVel1);

    pulse1 = 0;
    waktulama1 = waktusekarang1;
  }
}
