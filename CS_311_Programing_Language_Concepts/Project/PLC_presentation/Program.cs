//------------< CS_311 - Programming Language Concepts >------------
//------------< Group_4 - C# Language Tutorial >-----------------
// Student 1 Name : Aryan Jigneshbhai Bhagat                     NetID : sl5310
// Student 2 Name : Venkata Sai Krishna 1Aditya Vatturi          NetID : by4412 


// -------< First code of C# - Hello World (Pioneers) Program >---------

// using WriteLine: (appends new line)
Console.WriteLine("Hello Pioneers!");
// Console.WriteLine("This is my first code");

// using Write:
Console.Write("Hello Pioneers!");
// Console.Write("This is my first code");

Console.WriteLine();



// --------< Primitive Data Types and Variables >-------------

// 1. int
int num1 = 3;
Console.WriteLine(num1);

// 2. float/double/decimal
// float         6-9 digits
// double        15-17 digits
// decimal       28-29 digits
float num2 = 3.41f;
Console.WriteLine(num2);

// 3. bool
bool val = true;
Console.WriteLine(val);

// 4. char
char c = 'A';
Console.WriteLine(c);

// Implicit typed variable 'var' - data type declared after assigning the value
var name = "Group4";
Console.WriteLine(name);

// Array
string[] fraudulentOrderIDs = new string[3];
fraudulentOrderIDs[0] = "A123";
fraudulentOrderIDs[1] = "B456";
fraudulentOrderIDs[2] = "C789";
Console.WriteLine($"First: {fraudulentOrderIDs[0]}");
Console.WriteLine($"Second: {fraudulentOrderIDs[1]}");
Console.WriteLine($"Third: {fraudulentOrderIDs[2]}");
//access array using foreach
string[] names = { "Aryan", "Aditya", "Prapti" };
foreach (string i in names)
{
    Console.Write(i);
    Console.Write(", ");
}

// ----------< Arithmetic Operation >-------------

// + is the addition operator
// - is the subtraction operator
// * is the multiplication operator
// / is the division operator
int sum = 7 + 5;
int difference = 7 - 5;
int product = 7 * 5;
int quotient = 7 / 5;
Console.WriteLine("Sum: " + sum);
Console.WriteLine("Difference: " + difference);
Console.WriteLine("Product: " + product);
Console.WriteLine("Quotient: " + quotient);

// Casting:
int first = 7;
int second = 5;
decimal ans = (decimal)first / (decimal)second;
Console.WriteLine(ans);

// Conversion:
int a = 5;
int b = 7;
string message = a.ToString() + b.ToString();
Console.WriteLine(message);

// order of operations: 
int value1 = 3 + 4 * 5;
int value2 = (3 + 4) * 5;
Console.WriteLine(value1);
Console.WriteLine(value2);

//Example: convert Fahrenheit to Celsius
int fahrenheit = 94;
decimal celsius = (fahrenheit - 32m) * (5m / 9m);
Console.WriteLine("The temperature is " + celsius + " Celsius.");



//---------< Selection Statements >-----------

// if..else..statements
//Same syntax and code blocks as compare to C++ lang
// if (condition)
// {
//     statements.....;
// }
// else if (condition)
// {
//     statements......;
// }
// else
// {
//     statements.....;
// }

//example:
int n1 = 5, n2 = -8;
if (n1 + n2 > 0)
{
    Console.WriteLine("Sum is Positive");
}
else if (n1 + n2 < 0)
{
    Console.WriteLine("Sum is Negative");
}
else
{
    Console.WriteLine("Sum is Zero");
}


// Switch Statements:
int employeeLevel = 200;
string employeeName = "John Smith";
string title = "";
switch (employeeLevel)
{
    case 100:
        title = "Junior Associate";
        break;
    case 200:
        title = "Senior Associate";
        break;
    case 300:
        title = "Manager";
        break;
    case 400:
        title = "Senior Manager";
        break;
    default:
        title = "Associate";
        break;
}
Console.WriteLine($"{employeeName}, {title}");


// do-while and while loop
Random random = new Random();
int current = random.Next(1, 11);
// do
// {
//     current = random.Next(1, 11);
//     Console.WriteLine(current);
// } while (current != 7);

while (current >= 3)
{
    Console.WriteLine(current);
    current = random.Next(1, 11);
}
Console.WriteLine($"Last number: {current}");


// -------< sub-programs / methods / functions: >-----------
float USDToINR(double usd)
{
    float rate = 84.69f;
    return (rate * (float)usd);
}
double usd = 50;
float INR = USDToINR(usd);
Console.WriteLine($"{usd} USD = {USDToINR(usd)} INR");



// --------< Object Oriented Programming Concepts>---------------


// Classes and Objects
class Car1
{
    string color = "red";
    static void Main(string[] args)
    {
        Car1 myObj1 = new Car1();
        Car1 myObj2 = new Car1();
        Console.WriteLine(myObj1.color);
        Console.WriteLine(myObj2.color);
    }
}


                
// Inheritance
class Vehicle  // base class (parent) 
{
    public string brand = "Ford";
    public void honk()
    {
        Console.WriteLine("Tuut, tuut!");
    }
}
class Car2 : Vehicle  // derived class (child)
{
    public string modelName = "Mustang";
}
class Program1
{
    static void Main(string[] args)
    {
        Car2 myCar = new Car2();
        myCar.honk();
        Console.WriteLine(myCar.brand + " " + myCar.modelName);
    }
}


