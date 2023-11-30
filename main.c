#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/include/quicksort.h"

/*
El programa debe generar identidades que contendrán:
- nombre
- apellido
- nacionalidad
- documento
- edad

Los datos se almacenarán en un archivo llamado: "data.txt"
el menú permitirá leer los datos, ordenarlos, agregar uno nuevo o eliminar uno
*/

#define PATH "../data.txt"

struct node{
    char name[20];
    char lastname[20];
    int age;
    char nationality[20];
    int document;
};

int menu(){
    int option = 0;
    printf("Select an option of the menu:\n");
    printf("1 - See the registration \n2 - Order the registration \n3 - Add a register \n4 - Delete a register \n5 - Delete file of registrations \n0 - End program \n\n");
    printf("Option: ");
    scanf("%d", &option);

    return option;
}

void read(int error_action){
    int age=0, document=0, registers=0;
    char name[20]="", lastname[20]="", nationality[20]="";
    FILE *fd;
    fd = fopen(PATH, "r");

    if(NULL == fd){
        if(0 == error_action){
            printf("File not found, there's nothing to delete\n\n");
        }else{
            perror("Registration file not found\n");
            fd = fopen(PATH, "w");
            printf("creating it...\n");
        
            if(NULL == fd){
                printf("Error, couldn't make the file, aborting");
                exit(1);
            }else{
                fclose(fd);
                printf("File created correctly");
            }
        }
    }else{
        printf("------------------------------------------\n");
        while(!feof(fd)){
            fscanf(fd, "%s %s %d %s %d", name, lastname, &age, nationality, &document);
            if(0 != age && 0 != document && 0 != strcmp("", name) && 0 != strcmp("", lastname) && 0 != strcmp("", nationality)){
                printf("%s %s %d %s %d \n", name, lastname, age, nationality, document);
                registers++;
                //push(name, lastname,....)
            }
        }


        printf("\n\n");
        if(0 == registers){
            printf("The file's empty");
        }else if(1 == registers){
            printf("There's 1 registration");
        }else{
            printf("There're %d registrations", registers);
        }
        printf("\n------------------------------------------\n");

        fclose(fd);
    }

    printf("\n\n");
}

void push(){
    // ask for a country or choose randomly, add all the names into an array and do the same with the lastnames
}

void delete(){
    // show the records and ask for deleting one
    read(0);
}

void delete_data(){
    remove(PATH);
    printf("The file of registrations was deleted correctly\n\n");
}


int main(void){
    int option = 5;

    printf("Welcome to IM \n\n");
    
    do
    {
        option = menu();

        switch (option)
        {
        case 0:
            printf("Program finished\n");
            break;
        case 1:
            read(1); // send a 1 for the case in whitch the file doesn't exist, in that case it creates the file
            break;
        case 2:
            order();
            break;
        case 3:
            push();
            break;
        case 4:
            delete();
            break;
        case 5:
            delete_data();
            break;
        default:
            printf("The selected option is uknown");
            break;
        }
    } while (0 != option);
    


    return 0;
}