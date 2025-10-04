string studentName = "Aryan Bhagat";
string course1Name = "PLC 311";
string course2Name = "DSA 301";
string course3Name = "ML 667";
string course4Name = "ADS 601";


int course1Credit = 3;
int course2Credit = 3;
int course3Credit = 4;
int course4Credit = 4;


int gradeA = 4;
int gradeB = 3;

int course1Grade = gradeA;
int course2Grade = gradeB;
int course3Grade = gradeB;
int course4Grade = gradeB;


int totalCreditHours = 0;
totalCreditHours += course1Credit;
totalCreditHours += course2Credit;
totalCreditHours += course3Credit;
totalCreditHours += course4Credit;


int totalGradePoints = 0;
totalGradePoints += course1Credit * course1Grade;
totalGradePoints += course2Credit * course2Grade;
totalGradePoints += course3Credit * course3Grade;
totalGradePoints += course4Credit * course4Grade;


Console.WriteLine($"Student: {studentName}\n");
Console.WriteLine("Course\t\t\tGrade\t\tCredit Hours");

// Console.Write("Total Grade Point: ");
// Console.WriteLine($"{totalGradePoints}");
// Console.Write("Total Credit Hours: ");
// Console.WriteLine($"{totalCreditHours}");

decimal gradePointAverage = (decimal) totalGradePoints/totalCreditHours;

int leadingDigit = (int) gradePointAverage;
int firstDigit = (int) (gradePointAverage * 10 ) % 10;
int secondDigit = (int) (gradePointAverage * 100 ) % 10;


Console.WriteLine($"{course1Name}\t\t\t{course1Grade}\t\t{course1Credit}");
Console.WriteLine($"{course2Name}\t\t\t{course2Grade}\t\t{course2Credit}");
Console.WriteLine($"{course3Name}\t\t\t{course3Grade}\t\t{course3Credit}");
Console.WriteLine($"{course4Name}\t\t{course4Grade}\t\t{course4Credit}");

Console.WriteLine($"\nFinal GPA:\t\t{leadingDigit}.{firstDigit}{secondDigit}");


