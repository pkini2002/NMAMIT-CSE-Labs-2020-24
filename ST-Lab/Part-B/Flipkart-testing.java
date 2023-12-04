package p3;

import java.util.Scanner;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;

public class Hello {
	public static void main(String args[]) {
		Scanner s=new Scanner(System.in);
		
		System.setProperty("webdriver.gecko.driver","/home/student/geckodriver");
		
		String url="https://www.flipkart.com";
		WebDriver driver=new FirefoxDriver();
		driver.get(url);
		
		String expected="Online Shopping Site for Mobiles, Electronics, Furniture, Grocery, Lifestyle, Books & More. Best Offers!";
		if(driver.getTitle().equals(expected)) {
			System.out.println("Web page opened successfully");
		}
		else {
			System.out.println("Did not open successfully");
		}
		try {
			Thread.sleep(5000);
		}catch(InterruptedException e) {
			e.printStackTrace();
		}
		driver.close();
	}
}
