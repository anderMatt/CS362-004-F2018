package src;
/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;


/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */


public class ramanats_tests extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public ramanats_tests(String testName) {
      super(testName);
   }

   
   //Manual tests to check the validity of specific url's
   public void testManualTest()
   {
	   System.out.println("Testing for testManualTest()...");
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	   //Testing valid scheme,authority,port, expect True
	   System.out.println(urlVal.isValid("http://www.facebook.com"));

	   //Testing valid scheme,authority,port,and path expect True
       System.out.println(urlVal.isValid("https://www.facebook.com/index_3.jpeg"));

       //Testing valid scheme,authority,port,path and  valid query expect True
       System.out.println(urlVal.isValid("https://www.facebook.com/index_3=mode&42adress_12.html"));

       //Testing valid scheme, invalid authority,port, and valid path expect false
       System.out.println(urlVal.isValid("https://_www.facebook.com_/index_10"));

       //Testing invalid scheme,valid authority,valid port, expect false
       System.out.println(urlVal.isValid("httttps://www.facebook.com/index12.html"));
	   
   }

   
   //Tests the path of a given url (If path AND url correct, tests pass)
    public void testIsValidPath() {

        System.out.println("Testing for testIsValidPath()...");
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

        String baseUrl = "http://www.google.com:80";
        String url;
        Boolean urlValid;

        for (ResultPair j : testUrlPath) {
            url = baseUrl + j.item;
            urlValid = urlVal.isValid(url);
            if ((j.valid && urlValid) || (!j.valid && !urlValid)) {
                System.out.println("Passed: URL -> <" + url + ">    Expected: " + j.valid + ". Actual: " + urlValid);
            } else {
                System.out.println("Failed: URL -> <" + url + ">    Expected: " + j.valid + ". Actual: " + urlValid);
            }
        }
    }

    
    // 
    ResultPair[] testUrlScheme = { new ResultPair("http://", true), new ResultPair("https://", true),
            new ResultPair("ftp://", true), new ResultPair("blah://", true), new ResultPair("://", false),
            new ResultPair("/", false), new ResultPair(":", false), new ResultPair("123", false),
            new ResultPair("!!", false), new ResultPair("http:", false), };

    ResultPair[] testUrlAuthority = { new ResultPair("www.google.com", true), new ResultPair("google.com", true),
            new ResultPair("192.168.0.0", true), new ResultPair("1000.1000.1000.1000", false), new ResultPair("1.1.1.256", false),
            new ResultPair("1000.10.10.10", false), new ResultPair("....", false), new ResultPair("abc", false),
            new ResultPair("123", false), new ResultPair(".a.b.a.", false) };

    ResultPair[] testUrlPort = { new ResultPair("", true), new ResultPair(":80", true), new ResultPair(":8080", true),
            new ResultPair(":80808", true), new ResultPair(":808080", false), new ResultPair(":8a", false),
            new ResultPair(":8A", false), new ResultPair(":88A8", false), new ResultPair(":8AAAAA", false),
            new ResultPair(":!@#", false), new ResultPair(":-100", false) };

    ResultPair[] testUrlPath = { new ResultPair("", true), new ResultPair("/blah", true), new ResultPair("/.", true),
            new ResultPair("/..", false), new ResultPair("/...", false), new ResultPair("/?", true),
            new ResultPair("/??", true), new ResultPair("/blah/foo", true), new ResultPair("/blah/foo/bar", true) };

    ResultPair[] testUrlQuery = {new ResultPair("?action=view", true),
            new ResultPair("?action=edit&mode=up", true),
            new ResultPair("", true)
    };
}
