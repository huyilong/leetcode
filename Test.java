import java.io.*;

//the file name must be identical with the name of the java file 
//must have the public static void main(String[] args) in this public class
//just as the int main(int argc, char** argv) in c++
//in the c++ the main method could be seperated from the class
//and if the method defined in the class if of the static type 
// there is no need in main to instaintialize the class just use the scope operator is fine
// if the method is not the static type then you must initialize an object to call the function
public class Test{

	public void hello(){
		System.out.println("hello in a non-static function -> must use the constructor!");
	}

	private static void hhello()
	{
		System.out.println("hhello in the static function!");
	}

	public static void main(String[] args)
	{
		Test obj = new Test();//using the default constructor in java
		
		obj.hello();

		hhello();
	}
}