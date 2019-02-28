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

double angle_of_second_hand(){
	return(second() * 6);
}

double angle_of_minute_hand(){
	return((angle_of_second_hand() / 360 * 6) + (6 * minute()));
}

double angle_of_hour_hand(){
	return((angle_of_minute_hand() / 360 * 30) + (30 * corrected_hour_for_angle()));
}

double radius(int const x){
	return((x - 50) / 2);
}

void line_and_turn(int const x, int const y, int const n, double const pi){
	if (n>0){
		draw_distance((2 * pi*radius(x)) / 360);
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

void main(){
	int const x = 300;                                                                   //defines window size in x direction
	int const y = 600;                                                                   //degines window size in y direction
	int const n = 360;
	double const pi = acos(-1.0);
	make_window(x, y);
	circle_para(x, y, n, pi);

}
