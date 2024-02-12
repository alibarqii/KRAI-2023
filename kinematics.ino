void kinematics(int vx, int vy, int w) {
  float motor1 = 0.7071 * (vy - vx) + (w * 0.471);
  rpm_m1 = motor1 * 1.504050;
  if (rpm_m1 > 0) {
    dir1 = 1;
  }
  else if (rpm_m1 < 0) {
    dir1 = -1;
  }
  else {
    rpm_m1 = 0;
  }
}
