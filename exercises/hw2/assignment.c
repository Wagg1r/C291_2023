#include <stdio.h>

int main(void){
	char emp;	
	float inputnum;
	float GS_total_salary = 0;
	float F_overload= 0;
	float M_faculty_Avg = 0;
	float W_faculty_Avg= 0;
	float F_total_salary = 0;
	int TA_hours = 0;
	int H_hours = 0;
	int Faculty_counter = 0;
	int Staff_counter = 0;
	int GS_overtime = 0;
	int F_counter = 0;
	char OTresponse;
	float H_hours_total= 0;
	float overload_total = 0;
	float M_Faculty_overtime = 0;
	float W_Faculty_overtime= 0;
	float M_Faculty_Avg = 0;
	float W_Faculty_Avg = 0;
	float M_Staff_Avg = 0;
	float W_Staff_Avg = 0;
	float M_Hourly_Salary = 0;
	float M_Hourly_Pay = 0;
//handle overtime however I want since he did not specify how to do that.
//salary is what youre supposed to get
//pay is salary + overtime
	//GS_total_salary = 0;
	//Staff_counter = 0;
	//M_Staff_Avg = 0;
	//W_Staff_Avg = 0;

	while (emp != 'Q'){
	printf("Enter employee letter: ");
	scanf(" %c", &emp);
	switch (emp){
	case 'A':
		printf("\nYou entered %c, which is Admin \n", emp);
		printf("What is the Admin's salary?");
		scanf("%f", &inputnum); // asking the user for input once they have selected admin
		GS_total_salary += inputnum; //take the input they give and add it to the rest of the salaries given before to make average later
		Staff_counter += 1; // counts the number of employees in this category
		M_Staff_Avg = (GS_total_salary/Staff_counter)/12; // takes the total salary for all employees and averages with number of employees divided by the number of months 12
		W_Staff_Avg = (M_Staff_Avg/4);// take the month average and get that in weeks
		GS_overtime += M_Staff_Avg;
		printf("Average Monthly for staff: %f \n", M_Staff_Avg);
		printf("Average Weekly for Staff: %f  \n", W_Staff_Avg);
		printf("Average overtime: %f  \n", GS_overtime+M_Staff_Avg);
		break;
	case 'S':
                printf("\n You entered %c, which is Staff \nWhat is the staff's salary and then number of overtime hours per month?: ", emp);
		scanf("%f %d", &inputnum,&GS_overtime); // ask user for staff input
		if (GS_overtime > 10){ // make sure its under allowed terms if not ask again.
			printf("Staff should be limited to 10 hours are you sure this is right? (Y/N)");
			scanf(" %c", &OTresponse);
			// printf("%c", OTresponse);
			switch(OTresponse){
			case 'Y': //this was my interpretation of the bonus Seiffert told me this was incorrect but can work for extra credit
				printf("thank you please continue \n");
				break; //if the person respondes yes nothing happens
			case 'N' :
				printf("enter correct amount of time: ");
				scanf(" %d", &GS_overtime);
				break;//ends else if / take in the correct amount of time.
			default :
				printf("incorrect input try again");
				break;//ends else catch all other inputs
			}// ends switch??
		}//end if
		//printf("overtime: %d  \n", GS_overtime);
				// GS_overtime = (inputnum/1920)*GS_overtime*1.5);// overtime is %150 of salary so find out how their pay is
		//printf("overtime: %d  \n", GS_overtime);
		GS_total_salary += inputnum; //take all salaries and group them together
                Staff_counter += 1; //count the number of employees
                M_Staff_Avg = (GS_total_salary/Staff_counter)/12; //
                W_Staff_Avg = (M_Staff_Avg/4);
		GS_overtime = (((inputnum/1920)*GS_overtime*1.5)+M_Staff_Avg)/Staff_counter;// overtime is %150 of salary so find out how their pay is

		printf("Average Monthly for staff: %f \n", M_Staff_Avg);
                printf("Average Weekly for Staff: %f  \n", W_Staff_Avg);
		printf("Average overtime: %f  \n", GS_overtime+M_Staff_Avg);
		break;
	case 'R':
		printf("\n You entered %c, which is Regular Faculty \n What is the Regular Faculty's salary and overload credit hours?: ", emp);
                scanf("%f %f", &inputnum,&F_overload); // ask user for staff input
			//printf("input number: %f \n", inputnum);
		F_total_salary += inputnum; // takes all sallaries and adds them together.
			//printf("total salary: %f \n", F_total_salary);
		Faculty_counter += 1; // counts the number of Faculty
			//printf("faculty counter: %d \n", Faculty_counter);
		M_Faculty_Avg = (F_total_salary/Faculty_counter)/10; // this takes the total salary divides it by the number of people and then divides by 12 months for monthly pay
		W_Faculty_Avg = M_Faculty_Avg/4; //this calulates what the  weekly average pay is based on the Monthly pay

		overload_total += (F_overload*(8500/3)); // take the overload hours and multiply them by how much $ for each credit hour 8500/3 and divide by 5 for each month in the semester
			//printf("overload: %f overload_total: %f\n",F_overload, overload_total);
		M_Faculty_overtime += overload_total/10; //take the total overload and divide it by 5 (5 months for each semester) to get how much they are being paid monthly for overload
	
		M_Faculty_overtime += M_Faculty_Avg;
		printf("Average Monthly for Faculty: $%f \n", M_Faculty_Avg);
                printf("Average Weekly for Staff: $%f  \n", W_Faculty_Avg);
                printf("Average  pay :$%f  \n", M_Faculty_overtime);

		break;
	case 'J':
                printf("\n You entered %c, which is Adjunct \nHow many credit hours do they teach?\n ", emp);
		scanf("%f", &inputnum);

		inputnum = inputnum*566.6666666;// take how many hours they worked and convert it to total money earned per semester
		F_total_salary += inputnum; //add the money earned for the whole semester for all faculty
		M_Faculty_overtime += F_total_salary;
		Faculty_counter += 1; //count the number of faculty
		M_Faculty_Avg = ((F_total_salary/Faculty_counter)/5);//take the total salary and divide it by 5 months
		W_Faculty_Avg = M_Faculty_Avg/4;
 		printf("Average Faculty Monthly for Faculty: $%f \n", M_Faculty_Avg);
                printf("Average Faculty Weekly for Staff: $%f  \n", W_Faculty_Avg);
                printf("Average Faculty pay :$%f  \n", M_Faculty_overtime);
                break;
	case 'T':
		//the instructions say TAs are paid $2500 per course
 	      	printf("\n You entered %c, which is TA \nHow many courses and hours have they worked?", emp);
                scanf("%f %d", &inputnum, &TA_hours);
		inputnum = inputnum * 2500;// number of courses times the pay per course
		Faculty_counter += 1; //count the number of faculty
		F_total_salary += inputnum; //add the money earned for the whole semester fo>
		M_Faculty_Avg = ((F_total_salary/Faculty_counter)/5);//take the total salary>
                W_Faculty_Avg = M_Faculty_Avg/4; //divide monthly by 4 to get weekly
		M_Faculty_overtime = M_Faculty_Avg;
                printf("Average Faculty Monthly for Faculty: $%f \n", M_Faculty_Avg);
                printf("Average Faculty Weekly for Staff: $%f  \n", W_Faculty_Avg);
                printf("Average Faculty overload pay :$%f  \n", M_Faculty_overtime);

 		break;
	case 'H':
               	printf("\n You entered %c, which is Hourly \nEnter their hourly wage and hours worked this month: ", emp);
		scanf(" %f %d", &inputnum, &H_hours);
		H_hours_total += H_hours*H_hours*1.25;//total pay
		if(H_hours/4>20){
		M_Hourly_Salary = 20*inputnum;
		M_Hourly_Pay = (H_hours/4)*inputnum;
		}//ends if
		else{
		M_Hourly_Salary = (H_hours/4)*inputnum;
                M_Hourly_Pay = (H_hours/4)*inputnum;
		}//ends else
		printf("monthly Hourly pay is %f \n",M_Hourly_Pay);
		printf("monthly Hourly salary is %f \n",M_Hourly_Salary);
		printf("Weekly Hourly salary is %f \n", M_Hourly_Salary/4);


		break;
	case 'Q':
		printf("\n \n thank you ending now \n");
		printf("Average Staff Monthly for staff: %f \n", M_Staff_Avg);
                printf("Average Staff Weekly for Staff: %f  \n\n", W_Staff_Avg);

		printf("Average Faculty Monthly for Faculty: $%f \n", M_Faculty_Avg);
                printf("Average Faculty Weekly for Staff: $%f  \n", W_Faculty_Avg);
                printf("Average Faculty overload pay :$%f  \n\n", M_Faculty_overtime);


		printf("monthly Hourly pay is %f \n",M_Hourly_Pay);
                printf("monthly Hourly salary is %f \n",M_Hourly_Salary);
                printf("Weekly Hourly salary is %f \n\n", M_Hourly_Salary/4);



		break;
	case '?':
		printf("use A for Admin, S for Staff, R for regular Faculty, J for Adjunct, T for TA, or H for Hourly \n");
		break;
	default : 

	 printf("this is not a valid entry (%c) \n", emp); //bonus validating answers.
		break;

		}//ends switch
	 }// ends while loop
return 0;
} // ends main
