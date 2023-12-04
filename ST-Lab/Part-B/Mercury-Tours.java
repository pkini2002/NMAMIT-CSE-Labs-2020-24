package p1;

import java.util.Scanner;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;

public class Hello {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s=new Scanner(System.in);
		System.setProperty("webdriver.gecko.driver", "C:\\Users\\HP\\Downloads\\geckodriver");
		
		System.out.println("Enter the expected title:");
		String expected=s.nextLine();
		
		String url="http://demo.guru99.com/test/newtours";
		
		WebDriver driver=new FirefoxDriver();
		driver.get(url);
		
		if(driver.getTitle().equals(expected)) {
			System.out.println("Success! Test passed");
		}
		else {
			System.out.println("Failed! Test failed");
		}
		driver.close();
	}

}
