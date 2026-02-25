#include<iostream>
#include<string>
#include<curl/curl.h> 

//1.helper function
size_t WriteCallback(void* contents,size_t size,size_t nmemb,std::string* user_string)
{
    user_string->append((char*)contents,size*nmemb);
    return size*nmemb;
}

int main()
{
    CURL* curl;
    CURLcode res;
    std::string api_data;

    curl=curl_easy_init();

    if(curl)
    {
        //2. the endpoint
        curl_easy_setopt(curl,CURLOPT_URL,"https://official-joke-api.appspot.com/random_joke");

        //3.endpoint rules
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,WriteCallback);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA,&api_data);

        //4.The request
        res=curl_easy_perform(curl);

        //5.outputting the recieved data
        std::cout << "--- Data received from the API ---\n";
        std::cout << api_data << "\n";
    }
}