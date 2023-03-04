/* COVID-19 Patient Management System
CO 253 - Mini Project
Date: 1/10/2022
Author: SELLAHEWA I.B. E/18/324
E18324_Project.c
*/

// Importing the wanted libraries
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Defining the four functions before the main function
void newPatient();
void printPatient();
void printallRecords();
void deletePatient();
int checkNumber(char*);

// Defining the structure of a one patient 
typedef struct 
{
    long long NIC;
    int age;
    char fullName[50];
    char gender[10];
    char admissionDate[20];

}patient;

// defining array for store the patients details
// This program has written for the maximum number of 1000000 patients
patient information [1000000];

// Taking pateint count as 0. This will be keep updating when new pateints added
int patientcount = 0;

int main(){
    // Defining a variable for get the task. 
    //This defined as char because if user enters a letter it must be a confusion in program 
    char* task=(char*)malloc(100*sizeof(char));

    // Printing the welcome message
    printf("-------------------------------------------------------\n");
    printf("WELCOME ... !!! \n");
    printf("COVID 19 PATIENT MANAGEMRNT SYSTEM\n");
    while (1)
    {
        
        // Printing the options menu 
        printf("-------------------------------------------------------\n");
        printf("0. Quit\n1. Add a Patient Record\n2. Print a Patient Record\n3. Print all Patients Records\n4. Delete a Patient Record\n");
        printf("-------------------------------------------------------\n");

        // Take the users input, askingwhich option does the user need.
        printf("Enter Option [0-4]\n");
        scanf("%s",task);
        printf("-------------------------------------------------------\n");

        // If the task number is 1, then redirect to the newpatients function
        if(atoi(task) == 1 ){ 

            int repeat_Add; //declare a variable for repeating question
            while(1){
                newPatient();  // call the new patient function

                // Ask to call the function again for another patient
                printf("Do you want to add another patient [1-Yes/0-No]  : ");
                scanf("%d",&repeat_Add);  // take the users input

                if(repeat_Add==1){
                    continue;  // if yes loop runs again and get another patient
                }
                else{
                    break;  // if not break the loop and go for a another task
                }

            }
        }

        // If the task number is 2, then redirect to the printpatients function
        else if(atoi(task) == 2 ){ 
            int repeat_Print; //declare a variable for repeating question
            while(1){
                printPatient(); // call the print patient function
                // Ask to call the function again for another patient
                printf("Do you want to print another patient [1-Yes/0-No]  : ");
                scanf("%d",&repeat_Print); // take the users input
                if(repeat_Print==1){
                    continue;  // if yes loop runs again and get another patient
                }
                else{
                    break;  // if not break the loop and go for a another task
                }

            }
        }

        // If the task number is 3, then redirect to the printallrecords function
        else if(atoi(task) == 3 ){ 
            printallRecords();  // call the print all records function
        }

        // If the task number is 4, then redirect to the deletepatients function
        else if(atoi(task) == 4 ){ 
            
            int repeat_Delete; //declare a variable for repeating question
            while(1){
                deletePatient(); // call the delete patient function

                // Ask to call the function again for another patient
                printf("Do you want to delete another patient [1-Yes/0-No]  : ");
                scanf("%d",&repeat_Delete);  // take the users input

                if(repeat_Delete==1){
                    continue;  // if yes loop runs again and get another patient
                }
                else{
                    break;   // if not break the loop and go for a another task
                }

            }
        }

        // If 0 is entered we stop the programme 
        else if(strcmp(task,"0")==0){
            break;   // break the loop
            return 0;
        }

        // If user enters number or a character other than a number from 0-4,
        // then prints a message for enter a valid option
        else 
        {
            printf("Please Enter a valid option [0-4] ... !!!\n");
            continue;     // then continues the programe for next loop until valid input comes 
        }        
    }
}  

// Function for get the new pateints' details
void newPatient(){

    // printing messege to the user to enter the details
    printf("Enter the Patients Details,\n-------------------------------------------------------\n");
    // assign variable for get the input
    char* var=(char*)malloc(100*sizeof(char));
    // check the validation of the NIC number by checking the length of the NIC number 
    // run the while loop until a valid NIC number entered 

    while(1){
        // printing messege to the user to enter the NIC number
        printf("Enter the NIC of the Pateint (only the number without V): ");
        scanf("%s",var);
        // check the validation of the NIC number by checking the length of the NIC number
        if(checkNumber(var)==0 || (strlen(var)!=9 && strlen(var)!=12)){
            // print invalid number if it is invalid
            printf("INVALID ID NUMBER (NIC should be 9 digits or 12 digits number) \n\n");            
        }
        else{
            // if it is valid number take the input into the variable
            information[patientcount].NIC=atoll(var);
            break; // breaks the loop after valid input
        }
    }
    
    while(1){
        // printing messege to the user to enter the age
        printf("Enter the age of the Pateint: ");
        scanf("%s",var);
        // check the validity of the age 
        // check user enters 0 or a negative number the age is invalid

        if(checkNumber(var)==0){
            // if user enters 0 prints invalid age
            printf("INVALID AGE!\n\n");
        }
        else{
            if(atoi(var)<0){
                // if user enters negative input prints invalid age
                printf("INVALID AGE!(IT CAN NOT BE NEGATIVE)\n\n");
            }
            else{
                // if it is a positive number take it as a valid input and assign it to variable
                information[patientcount].age=atoi(var);
                break;   // breaks the loop after valid input
            }
        
        }
    }

    // get the full name as a input
    printf("Enter the Full Name of the Pateint:");
    scanf("%c",var);       //remove the new line charactor before getting the full name
    // get the name until new line character 
    scanf("%[^\n]s",information[patientcount].fullName);
    
    // Get the gender as a inputs
    printf("Enter the Gender of the Pateint: ");
    scanf("%s",information[patientcount].gender);

    // Get the admission date as a input
    printf("Enter the Admission Date: \n( Please enter the date in DD/MM/YYYY format):\n");
    scanf("%s",information[patientcount].admissionDate);
   
    patientcount++; // increase the patients count by 1 after getting the new patients details
    // Since we used static array with 1000000 elements. 
    // If the patient count is increased more than 1000000 function will be exited
    if(patientcount>1000000){
        printf(" Maximum number of patients that can be entered has exceeded");
        return;
    }

}

// Function for print the one pateints' details
void printPatient(){
    // declare variable for get the NIC number of the patient whom should be printed
   
    char* var=(char*)malloc(100*sizeof(char));
    while(1){
         // printing messege to the user to enter the NIC number
        printf("Enter the Patients' NIC number(without V) which you want to view: \n");
        scanf("%s",var);
        // check the validation of the NIC number by checking the length of the NIC number
        if(checkNumber(var)==0 || (strlen(var)!=9 && strlen(var)!=12)){
            // print invalid number if it is invalid
            printf("INVALID ID NUMBER (NIC should be 9 digits or 12 digits number)\n\n");
        }
        else{
            // if it is a valid input break this loop and go to the printing loop
            break;
        }
    }
    int success=0;
    
    // get the information in the array one by one 
    for(int i=0;i<patientcount; i++){
        if(atoll(var) == information[i].NIC){
            // print the NIC number
            printf("\nNIC number of the patient: %lld \n",information[i].NIC);
            // print the Full name
            printf("Full name of the patient: %s\n",information[i].fullName);
            // print the age
            printf("Age of the patient: %d\n",information[i].age);
            // print the gender
            printf("Gender of the patient: %s\n",information[i].gender);
            // print the admission date
            printf("Admission Date : %s\n",information[i].admissionDate);
            success=1; // variable for check whether user enters a correct NIC number 

        }
    }
    // If user enters wrong NIC number prints a messege 
    if(!success){
        printf("There is no patient with this NIC number\n\n");
    }
}

// Function for print the all records
void printallRecords(){

    // get the information in the array one by one 
    for(int i=0;i<patientcount; i++){

        // then print the reocrds of all patients one by one
        printf("(%d) ",i+1); // print the number in the list
        // print the NIC number 
        printf("NIC number of the patient: %lld \n",information[i].NIC);
        // print the Full name
        printf("    Full name of the patient : %s\n",information[i].fullName);
        // print the Age
        printf("    Age of the patient       : %d\n",information[i].age);
        // print the Gender
        printf("    Gender of the patient    : %s\n",information[i].gender);
        // print the Admission date
        printf("    Admission Date           : %s\n",information[i].admissionDate);
        printf("\n");

    }
}


// Function for delete the pateints' details
void deletePatient(){
    // declare variable for get the NIC number of the patient whom should be deleted
    //int m;
    

    char* var=(char*)malloc(100*sizeof(char));
    while(1){
        // printing messege to the user to enter the NIC number
        printf("Enter the Patients' NIC number(without V) which you want to delete: \n");
        scanf("%s",var);
        //check the validation of the NIC number by checking the length of the NIC number
        if(checkNumber(var)==0 || (strlen(var)!=9 && strlen(var)!=12)){
            // print invalid number if it is invalid
            printf("INVALID ID NUMBER (NIC should be 9 digits or 12 digits number)\n\n");
        }
        else{
            
            break;
        }
    }
    int success=0;

    // get the information in the array one by one 
    for(int i=0;i<patientcount; i++){
        if(atoll(var) == information[i].NIC){
            
            int t;
            // print the Full name
            printf("Full name of the patient: %s\n",information[i].fullName);
            // print the NIC number
            printf("NIC number of the patient: %lld \n",information[i].NIC);
            // Then asks that are you sure about deletion. because deletion cannot undone
            printf("Do you want to delete this patient [1-Yes/0-No]  : ");
            scanf("%d",&t);  // take the users input
            
            if(t==1){
                // if user enters 1 then it get as yes and delete the entry
                // deletion done by 
                for (int n=i;n<patientcount;n++){
                information[n]=information[n+1];
                }
                patientcount--;  // reducing the number of patients after deleting one patient
                // informs user that deletion is successful
                printf("-------- Successfully Deleted the record -------\n\n");
                // check the NIC number is in the system and if it is there, then sucess is 1
                success=1;
            }
            else if(t==0){
                // if user enters 0 it gets as 0 and cancel the deletion
                // and inform user that deletion is cancelled 
                printf("-------- Deletion was cancelled -------\n\n");
                // check the NIC number is in the system and if it is there, then sucess is 1
                success=1;
                break;
            }
            else{
                // if user enters other than 0 or 1 then informs him wrong input 
                printf("Wrong input \n");
            }
                    
        
        }
        

    }
    if(!success){
        // if sucess is 0 it means that NIC number is not in the system
        // Then prints there is no patient
        printf("There is no patient with this NIC number\n\n");
    }
}

//function for check whether the input is valid number 
// return 0 if input is not a number otherwise return 1
int checkNumber(char *string){

    int i=0;
    // going through each character of the string
    while (i<strlen(string)) {
        // check that character is a number or not
        if (isdigit(string[i])) {
            // if is a number move to the next character and continue
            i++;
            continue;
        }
        else{
            // if it is not a number return 0
            return 0;
        }
    }
    // if all the characters are numbers return 1
    return 1;
}