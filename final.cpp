//Programmed by Nick J
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

int fixed_hour(){	//i failed to make this where the 0 is implemented before a number less than 10, my fix is redundant but works
	if (hour() > 12 && (hour() - 12 > 9)){
		return(hour() - 12);
	}
	else if (hour() > 12 && (hour() - 12 <= 9)){
		return(hour() - 12);
	}
	else if (hour() == 0){
		return(12);
	}
	else if (hour() < 10){
		return(hour());
	}
	else{
		return(hour());
	}
}

int fixed_minute(){		//i failed to make this where the 0 is implemented before a number less than 10, my fix is redundant but works
	if (minute()>9){
		return(minute());
	}
	else{
		return(minute());
	}
}

int fixed_second(){		//i failed to make this where the 0 is implemented before a number less than 10, my fix is redundant but works
	if (second()>9){
		return(second());
	}
	else{
		return(second());
	}
}

int corrected_hour_for_angle(){
	if (hour() >= 12){
		return(hour() - 12);
	}
	else{
		return(hour());
	}
}


int year(){
	return(get_calendar_date() / 10000);
}

int day(){
	return(get_calendar_date() % 100);
}

int month_array_value(){
	return(((get_calendar_date() % 10000) / 100) - 1);
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
	return((x - 50) / 2.0);
}

double second_hand_length(int const x){
	return(.80*radius(x));
}

double minute_hand_length(int const x){
	return(.72*radius(x));
}

double hour_hand_length(int const x){
	return(.5*radius(x));
}

void line_and_turn(int const x, int const y, int const n, double const pi){
	if (n>0){
		draw_distance(2 * pi*radius(x) / 360);
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
	set_pen_width(4);
	set_pen_color(color::black);
	if (vari2 % 5 == 0 && vari2>0){
		move_to(x / 2.0, y / 2.0);
		move_distance(radius(x)*.90);
		draw_distance(radius(x)*.10);
		turn_right_by_degrees(6);
		sec_min_hour_ind(x, y, vari2 - 1);
	}
	else if (vari2>0){
		move_to(x / 2.0, y / 2.0);
		move_distance(radius(x)*.95);
		draw_distance(radius(x)*.05);
		turn_right_by_degrees(6);
		sec_min_hour_ind(x, y, vari2 - 1);
	}
}

void clock_hands_refresh(int const x, int const y){            //include the displa of time and date in this function too -- make three serpeate if statemetns more
	string pq;
	if (hour() >= 12){
		pq = "PM";
	}
	else{
		pq = "AM";
	}
	string const monthab[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	set_pen_color(color::black);
	set_pen_width(2);
	int s = angle_of_second_hand();
	int j = angle_of_minute_hand();
	int k = angle_of_hour_hand();
	int t = fixed_second();
	int g = fixed_minute();
	int b = fixed_hour();
	move_to(x / 7.0, y / 8.0);
	if (b > 9){
		write_string(b);
	}
	else {
		write_string("0");
		write_string(b);
	}
	write_string(":");
	if (g > 9){
		write_string(g);
	}
	else {
		write_string("0");
		write_string(g);
	}
	write_string(":");
	if (t > 9){
		write_string(t);
	}
	else {
		write_string("0");
		write_string(t);
	}
	write_string(" ");
	write_string(pq);
	write_string("       ");
	write_string(monthab[month_array_value()]);
	write_string(" ");
	if (day() > 9)
		write_string(day());
	else{
		write_string("0");
		write_string(day());
	}
	write_string(", ");
	write_string(year());
	if (1){
		move_to(x / 2.0, y / 2.0);
		set_heading_degrees(0);
		turn_right_by_degrees(s);
		draw_distance(second_hand_length(x));
		if (1){
			move_to(x / 2.0, y / 2.0);
			set_heading_degrees(0);
			turn_right_by_degrees(j);
			draw_distance(minute_hand_length(x));
			if (1){
				move_to(x / 2.0, y / 2.0);
				set_heading_degrees(0);
				turn_right_by_degrees(k);
				draw_distance(hour_hand_length(x));
				wait(.6);
				if (1){
					set_pen_width(5);
					set_heading_degrees(0);
					turn_right_by_degrees(s);
					set_pen_color(color::white);
					move_to(x / 2.0, y / 2.0);
					draw_distance(second_hand_length(x));
					if (1){
						set_heading_degrees(0);
						turn_right_by_degrees(j);
						move_to(x / 2.0, y / 2.0);
						draw_distance(minute_hand_length(x));
						if (1){
							set_heading_degrees(0);
							turn_right_by_degrees(k);
							move_to(x / 2.0, y / 2.0);
							draw_distance(hour_hand_length(x));
							move_to(x / 7.0, y / 8.0);
							if (b > 9){
								write_string(b);
							}
							else {
								write_string("0");
								write_string(b);
							}
							write_string(":");
							if (g > 9){
								write_string(g);
							}
							else {
								write_string("0");
								write_string(g);
							}
							write_string(":");
							if (t > 9){
								write_string(t);
							}
							else {
								write_string("0");
								write_string(t);
							}
							write_string(" ");
							write_string(pq);
							write_string("       ");
							write_string(monthab[month_array_value()]);
							write_string(" ");
							if (day() > 9)
								write_string(day());
							else{
								write_string("0");
								write_string(day());
							}
							write_string(", ");
							write_string(year());
							clock_hands_refresh(x, y);

						}
					}
				}
			}
		}
	}
}

void main(){
	cout << "How many pixels wide would you like your clock window to be?" << " (400 is solid)" << endl;
	int const x = read_int();
	int const y = 1.5 * x;
	int const n = 360;
	int const vari2 = 60;
	double const pi = acos(-1.0);
	make_window(x, y);
	circle_para(x, y, n, pi);
	set_heading_degrees(0);
	sec_min_hour_ind(x, y, vari2);
	clock_hands_refresh(x, y);
}
