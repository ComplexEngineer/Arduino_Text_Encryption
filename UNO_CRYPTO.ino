String charSet   = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
String plainText = "TEXT ERDEM";
String chperText = "";
String key       = "KS7F2W4R5X";


void setup() 
{
  Serial.begin(9600);
  delay(800);
  
  char charMap[charSet.length()][charSet.length()];
  for(byte i=0;i<charSet.length();i++)
  {
    for(byte j=0;j<charSet.length();j++)
    {
      charMap[i][j] = charSet[(i+j)%charSet.length()];
    }
  }

  for(byte i=0;i<plainText.length();i++)
  {
    byte indisX = 0;
    byte indisY = 0;
    
    for(byte j=0;j<charSet.length();j++)
    {
      if(plainText[i] == charSet[j])
      {
        indisX = j;
      }
      if(key[i % key.length()] == charSet[j])
      {
        indisY = j;
      }
    }
    chperText += String(charMap[indisX][indisY]);
  }
  Serial.println(chperText);
}

void loop() 
{
  
}
