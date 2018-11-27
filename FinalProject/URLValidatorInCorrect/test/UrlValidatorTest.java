

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {
   private int assertCount = 0;  // Number of executed test cases.
   private int passCount = 0;  // Number of test cases that pass.


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing	   
	   
   }
   
   
   public void testIsValidScheme() {  // First URL partition: Scheme.
      UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

      assertTrue("HTTP scheme is valid", validator.isValid("http://google.com"));
      assertTrue("FTP scheme is valid", validator.isValid("ftp://google/file"));
      assertTrue("FTPS scheme is valid", validator.isValid("ftps://path/to/my/file.txt"));
      assertTrue("TELNET scheme is valid", validator.isValid("telnet://localhost:5050"));

      assertFalse("Scheme cannot contain symbols", validator.isValid("ht!p://google.com"));
      assertFalse("Scheme cannot begin with numeric character", validator.isValid("0http://google.com"));


   }
   
   public void testIsValidAuthority() {  // Second URL partition: Authority.
		 //You can use this function to implement your Second Partition testing	   

   }

   public void testIsValidPort() {  // Third URL partition: Port.

   }

   public void testIsValidPath() {  // Fourth URL partition: Path.

   }

   public void testIsValidQuery() {  // Fifth URL partition: Query string.

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

      // Build URLs from permutations of scheme options, path options, etc.

   }


   private ResultPair[] getSchemeOptions() {
      ResultPair[] schemes = {
              new ResultPair("http://", true),
              new ResultPair("https://", true),
              new ResultPair("htt3p://", false),
              new ResultPair("1https://", false),
              new ResultPair("://", false)
      };

      return schemes;
   }




}
