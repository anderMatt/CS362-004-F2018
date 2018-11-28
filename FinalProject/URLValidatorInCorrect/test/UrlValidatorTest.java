

import junit.framework.TestCase;

import java.util.stream.Stream;

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
      assertTrue("FTPS scheme is valid", validator.isValid("ftps://google/file"));
      assertTrue("TELNET scheme is valid", validator.isValid("telnet://localhost:5050"));

      assertFalse("Scheme cannot contain symbols", validator.isValid("ht!p://google.com"));
      assertFalse("Scheme cannot begin with numeric character", validator.isValid("0http://google.com"));


   }
   
   public void testIsValidAuthority() {  // Second URL partition: Authority.
		 //You can use this function to implement your Second Partition testing	   

   }

   public void testIsValidPort() {  // Third URL partition: Port.
       UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

       assertTrue("Numeric port is valid", validator.isValid("http://google.com:80"));
       assertFalse("Negative port is invalid", validator.isValid("http://google.com:-80"));
       assertFalse("Alpha port is invalid", validator.isValid("http://google.com:abc"));
       assertFalse("Non-numeric port is invalid", validator.isValid("http://google.com:abc"));
       assertTrue("Large numeric port is invalid", validator.isValid("http://google.com:999999"));

   }

   public void testIsValidPath() {  // Fourth URL partition: Path.

   }

   public void testIsValidQuery() {  // Fifth URL partition: Query string.

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid() {
      // Construct a URL from each permutation of scheme, port, authority, path, and query string, and pass to
      // the validator.
       UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

       ResultPair[] schemes = getSchemes();
       ResultPair[] ports = getPorts();
       ResultPair[] authorities = getAuthorities();
       ResultPair[] paths = getPaths();
       ResultPair[] queryStrings = getQueryStrings();

       String url;
       boolean expected,
               actual;

       for(ResultPair scheme: schemes) {
         for(ResultPair authority: authorities) {
            for(ResultPair port: ports) {
               for(ResultPair path: paths) {
                  for(ResultPair query: queryStrings) {
                      expected = (scheme.valid && authority.valid && port.valid && path.valid && query.valid);
                      url = new StringBuilder(scheme.item)
                              .append(authority.item)
                              .append(port.item)
                              .append(query.item)
                              .append(path.item)
                              .toString();

                      System.out.println("Testing URL: " + url);
                      actual = validator.isValid(url);

                      if (actual != expected) {
                          System.out.println(String.format("\tFAILURE. Expected URL '%s' to be %s. Is actually considered %s", url,
                                  (expected ? "valid" : "invalid"),
                                  (actual ? "valid" : "invalid")));
                      } else {
                          System.out.println("\tpassed.");
                      }
                  }
               }
            }
         }
       }


   }


   private ResultPair[] getSchemes() {
      ResultPair[] schemes = {
              new ResultPair("http://", true),
              new ResultPair("https://", true),
              new ResultPair("htt3p://", false),
              new ResultPair("1https://", false),
              new ResultPair("://", false)
      };

      return schemes;
   }

   private ResultPair[] getPorts() {
      ResultPair[] ports = {
              new ResultPair("", true),
              new ResultPair(":80", true),
              new ResultPair(":-1", false),
              new ResultPair(":62111", true),
              new ResultPair(":!", false),
              new ResultPair(":abc", false),

      };

      return ports;
   }

   private ResultPair[] getAuthorities() {
      ResultPair[] authorities = {
              new ResultPair("google.com", true),
              new ResultPair("!", false),
              new ResultPair("100.100.100.100", true),
              new ResultPair("-----", false),
              new ResultPair("bad-authority.com", false),

      };

      return authorities;
   }

   private ResultPair[] getPaths() {
      ResultPair[] paths = {
              new ResultPair("/some/path", true),
              new ResultPair("", true),
              new ResultPair("/!!!/", false),
              new ResultPair("//abc", false),
              new ResultPair("~~", false),
      };

      return paths;
   }

   private ResultPair[] getQueryStrings() {
      ResultPair[] queryStrings = {
              new ResultPair("", true),
              new ResultPair("?q=valid", true),
              new ResultPair("@q=bad", false),
              new ResultPair("?q=valid&argument=valid", true),
              new ResultPair("~~", false),
      };

      return queryStrings;
   }



}
