#include "library.h"

int hour(){
	return(get_clock_time()/10000);
}

int minute(){
  return((get_clock_time()%10000)/100);
}

int second(){
  return(get_clock_time()%100);
}

int corrected_hour_for_clock(){
  if (hour()>12){
    return(hour()-12);
  }
  else if(hour()==0){
    return(12);
  else return(hour());
  }
}

int corrected_hour_for_angle(){
  if (hour()>=12){
    return(hour()-12);
  }
  else{
    return(hour());
  }
}

double angle_of_second_hand(){
  return(second()*6);
}

double angle_of_minute_hand(){
  return((angle_of_second_hand()/360*6)+(6*minute()));
}

double angle_of_hour_hand(){
  return((angle_of_minute_hand()/360*30)+(30*corrected_hour_for_angle()));
}

void main(){

}
