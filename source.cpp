#include "library.h"

int hour(){
	return(get_clock_time() / 10000);
}

int minute(){
	return((get_clock_time() % 10000) / 100);
}

int second(){
	return(get_clock_time() % 100);
}

int corrected_hour_for_clock(){
	if (hour()>12){
		return(hour() - 12);
  }
	else if (hour() == 0){
		return(12);
  }
	else return(hour());
}

int corrected_hour_for_angle(){
	if (hour() >= 12){
		return(hour() - 12);
	}
	else{
		return(hour());
	}
}

int fixed_minute(){
  if (minute()<10){
      return(0);
      return(minute());
  }
  else return(minute());
}

double angle_of_second_hand(){
	return(second() * 6);
}

double angle_of_minute_hand(){
	return((angle_of_second_hand() / 360 * 6) + (6 * minute()));
}

double angle_of_hour_hand(){
	return((angle_of_minute_hand()/360*30)+(30*corrected_hour_for_angle()));
}

double radius(int const x){
	return((x-50)/2.0);
}

double second_hand_length(){
  return(.80*radius());
}

double minute_hand_length(){
  return(.72*radius());
}

double hour_hand_length(){
  return(.5*radius());
}

void line_and_turn(int const x, int const y, int const n, double const pi){
	if (n>0){
		draw_distance(2*pi*radius(x)/360);
		turn_right_by_degrees(1);
		line_and_turn(x, y, n - 1, pi);
	}
}

void circle_para(int const x, int const y, int const n, double const pi){
	move_to((x / 2.0), (y / 2.0) - radius(x));
	set_heading_degrees(90);
	set_pen_color(color::black);
	set_pen_width(3);
	line_and_turn(x, y, n, pi);
}

void sec_min_hour_ind(int const x, int const y, int const vari2){
  move_to(x/2.0, y/2.0);
  if (vari2%5==0 && n>0){
    set_pen_color(color::black);
    draw_distance(radius());
    set_pen_color(color::white);
    draw_distance(17/20*radius());
    turn_right_by_degrees(6);
    sec_min_hour_ind(vari2-1);
  }
  else if (n>0){
    set_pen_color(color::black);
    draw_distance(radius());
    set_pen_color(color::white);
    draw_distance(19/20*radius());
    turn_right_by_degrees(6);
    sec_min_hour_ind(vari2-1);
  }
}

void clock_hands_refresh(int const x, int const y, bool const timeON){            //include the displa of time and date in this function too -- make three serpeate if statemetns more
  set_pen_color(color::black);
  set_pen_width(3);
  if (timeON==1){
    move_to(x/2.0,y/2.0);
    turn_right_by_degrees(angle_of_second_hand());
    draw_distance(second_hand_length());
    set_pen_color(color::white);
    draw_distance(second_hand_length());
    set_pen_color(color::black);
  }
    if (timeOn==1){
      move_to(x/2.0,y/2.0);
      turn_right_by_degrees(angle_of_minute_hand());
      draw_distance(minute_hand_length());
      set_pen_color(color::white);
      draw_distance(minute_hand_length());
      set_pen_color(color::black);
    }
      if (timeON==1){
        move_to(x/2.0,y/2.0);
        turn_right_by_degrees(angle_for_hour_hand());
        draw_distance(hour_hand_length())
        set_pen_color(color::white);
        draw_distance(hour_hand_length())
        clock_hands_refresh(timeON);
      }
}

void main(){
  cout << "How many pixels wide would you like your clock window to be?" << " (Around 350 is a good pick)" << endl;
  int const x = read_int();
  int const y = 2*x
	//int const x = 300;                                                                   //defines window size in x direction
	//int const y = 600;                                                                   //degines window size in y direction
	int const n = 360;
  int const vari2 = 60;
  bool const timeON = 1;
	double const pi = acos(-1.0);
	make_window(x, y);
  //string month[] = ["Jan", "Feb", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
	circle_para(x, y, n, pi);
  set_heading_degrees(0);
  sec_min_hour_ind(x, y, vari2);
  clock_hands_refresh(x, y, timeON);
}
