package p2;

import java.util.Scanner;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;

public class Hello {
    public static void main(String args[]) {
    	Scanner s=new Scanner(System.in);
    	System.setProperty("webdriver.gecko.driver","/home/student/geckodriver");
    	
    	String url="https://www.gmail.com";
    	WebDriver driver=new FirefoxDriver();
    	driver.get(url);
    	
    	System.out.println("Enter the title of the page");
    	String expected=s.nextLine();
    	
    	if(driver.getTitle().equals(expected)) {
    		System.out.println("Success: Title Match");
    		driver.findElement(By.id("identifierId")).clear();
    		driver.findElement(By.id("identifierId")).sendKeys("anonymoususer4650@gmail.com");
    		driver.findElement(By.id("identifierNext")).click();
    		
    		try {
    			Thread.sleep(5000);
    		}catch(Exception e) {
    			System.out.println(e);
    		}
    		
    		driver.findElement(By.name("Passwd")).sendKeys("prathiksha7624914650");
    		driver.findElement(By.id("passwordNext")).click();
    		
    		try {
    			Thread.sleep(5000);
    		}catch(Exception e) {
    			System.out.println(e);
    		}
    	}
    	else {
    		System.out.println("Failed: Mismatch title");
    	}
    	driver.close();
    }
}
