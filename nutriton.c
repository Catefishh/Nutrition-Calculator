#include <stdio.h>
#include <ctype.h>

/*
TO DO:
1. Implement main function call
2. Implement BMR calculation
3. Implement calculation of macronutrients
4. Implement TDEE calculation
5. Implement BMI calculation
*/

int main()
{
    int age, activityLevel;
    char gender;
    char unitOfWeight, unitOfHeight;
    float weight, height, BMR, TDEE, BMI, protein, carbs, fat;

    printf("Enter your age: ");
    scanf("%d", &age);
    while (getchar() != '\n')
        ; // Clear buffer

    printf("Enter your gender (M/F): ");
    scanf("%c", &gender);
    while (getchar() != '\n')
        ;
    gender = toupper(gender);

    printf("Enter your weight: ");
    scanf("%f", &weight);
    while (getchar() != '\n')
        ;

    printf("Enter the unit of measurement for your weight (kg/lb): ");
    scanf("%c", &unitOfWeight);
    while (getchar() != '\n')
        ;
    unitOfWeight = tolower(unitOfWeight);

    if (unitOfWeight == 'l')
    {
        weight *= 0.453592; // 1 lb = 0.453592 kg
    }
    else
    {
        weight = weight;
    }

    printf("Enter your height: ");
    scanf("%f", &height);
    while (getchar() != '\n')
        ;

    printf("Enter the unit of measurement for your height (cm/in): ");
    scanf("%c", &unitOfHeight);
    while (getchar() != '\n')
        ;

    unitOfHeight = tolower(unitOfHeight);
    if (unitOfHeight == 'i')
    {
        height *= 2.54; // 1 inch = 2.54 cm
    }
    else
    {
        height = height;
    }

    printf("\nSelect your activity level:\n");
    printf("----------------------------------------------------------------\n");
    printf("1. Sedentary (little or no exercise)\n");
    printf("2. Lightly active (light exercise / sports 1 to 3 days/week)\n");
    printf("3. Moderately active (moderate exercise / sports 3 to 5 days/week)\n");
    printf("4. Very active (hard exercise / sports 6 to 7 days/week)\n");
    printf("5. Super active (very hard exercise / physical job)\n");
    printf("------------------------------------------------------------------\n");
    printf("Enter your choice (1 - 5): ");
    scanf("%d", &activityLevel);
    while (getchar() != '\n')
        ;

    if (gender == 'M')
    {
        BMR = 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age); // Harris-benedict equation
    }
    else
    {
        BMR = 447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age);
    }

    switch (activityLevel)
    {
    case 1:
        TDEE = BMR * 1.2;
        break;

    case 2:
        TDEE = BMR * 1.375;
        break;

    case 3:
        TDEE = BMR * 1.55;
        break;

    case 4:
        TDEE = BMR * 1.725;
        break;

    case 5:
        TDEE = BMR * 1.9;
        break;

    default:
        printf("Invalid activity level selected. Defaulting to sedentary lifestyle.\n");
        TDEE = BMR * 1.2;
    }

    // Macronutrients split: 40/30/30 (carbs/protein/fat)

    carbs = (TDEE * 0.4) / 4;
    protein = (TDEE * 0.3) / 4;
    fat = (TDEE * 0.3) / 9;

    BMI = weight / ((height / 100) * (height / 100));

    printf("\nYour nutrition values are:\n");
    printf("BMR: %.2f kcal\n", BMR);
    printf("TDEE: %.2f kcal\n", TDEE);
    printf("BMI: %.2f\n", BMI);
    printf("-------------------------\n");
    printf("Carbs: %.2f g\n", carbs);
    printf("Protein: %.2f g\n", protein);
    printf("Fat: %.2f g\n", fat);

    return 0;
}