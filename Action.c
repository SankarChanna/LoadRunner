Action()
{
	
//==========================================Sample Rest service script=========================================================



//Sample JSON Request

//{  
//    "employee": {  
//        "name":       "sonoo",   
//        "salary":      56000,   
//        "married":    true  
//    }  
//}  

	
	web_reg_save_param("LoginResponse","LB=\"Status\":200,\"Severity\":\"","RB=\",","Search=ALL",LAST);
	                                                
	lr_start_transaction("Login");

	web_custom_request("Login",
	  "URL=https://Dummyexamples.com/home/login/",                
	   "Method=POST",
		"Resource=0",
		"EncType=application/json",
		"Mode=HTTP",
		"Body={\"employee\": {\"name\":\"sonoo\",\"salary\":56000,\"married\":true}}",
		LAST);
	
	respM = strcmp("SUCCESS", lr_eval_string("{LoginResponse}"));
	
	if(respM == 0)
		lr_end_transaction("Login", LR_AUTO);
	else
		lr_end_transaction("Login", LR_FAIL);
	
	lr_think_time(5);
	
	return 0;
}
