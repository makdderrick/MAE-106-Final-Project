// Initialize Variables
float pot1 = 0;
float pot2 = 0;
int DesiredSteeringAngle = 0;
int past_steering_angle =0;
int wire_switch = 4;
int PistonState = 0;
unsigned long time_now = 0;
int period = 0;
int period_off = 100;


void setup() {
  Serial.begin(9600);

  // Configure pullup input resistor to digital pin 4
  pinMode(wire_switch,INPUT_PULLUP);


}

void loop() {
// Reads in the values from the potentiometers
  pot1 = analogRead(A0);
  pot2 = analogRead(A1);

  DesiredSteeringAngle = (pot1*120/1023-60) * -1;
   
// 4 States with three varying speeds, when pot 2 is all the way CCW, piston state = 0 and car does not move

// Off State, no motion
  if(pot2 > 1000){
    PistonState = 0;
  }

// Slow Speed
  if(pot2 <= 1000 && pot2 > 666){
    period = 600;
    if(millis() >= time_now + period && PistonState == 1){
        time_now += period;    
        PistonState = 0;
    }
    
    if(millis() >= time_now + period_off && PistonState ==0){
      time_now += period_off;
      PistonState = 1;
    }
  }

// Mid Speed
  if(pot2 <= 666 && pot2 > 333){
    period = 300;
    if(millis() >= time_now + period && PistonState == 1){
        time_now += period;    
        PistonState = 0;
    }
    
    if(millis() >= time_now + period_off && PistonState ==0){
      time_now += period_off;
      PistonState = 1;
    }
  }

// Full Speed
  if(pot2 <= 333){
    period = 150;
    if(millis() >= time_now + period && PistonState == 1){
      time_now += period;    
      PistonState = 0;
    }
    
    if(millis() >= time_now + period_off && PistonState ==0){
      time_now += period_off;
      PistonState = 1;
    }S
  }

// Kill switch, if wire in digital pin 4 is plugged into ground
  if(digitalRead(wire_switch) == 0){
    DesiredSteeringAngle = 666;
    PistonState = 666;
  }

  Serial.print(PistonState);
  Serial.print(" ");
  Serial.println(DesiredSteeringAngle);
  
  
}
