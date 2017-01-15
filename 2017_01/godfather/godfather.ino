#define DO 0
#define RE 1
#define MI 2
#define FA 3
#define SO 4
#define RA 5
#define SI 6
#define DO2 7
#define NO_SOUND 8

void setup() {
  // put your setup code here, to run once:

  pinMode(13, OUTPUT);
}

void loop() {
    int freq[] = {523,587,659,698,784,880,987,1027,0};
    int score[13][2] = {
        { RE , 1 },
        { RA , 2 },
        { DO2 , 2 },
        { SI , 2 },
        { RA , 2 },
        { DO2 , 2 },
        { RA , 2 },
        { SI , 2 },
        { RA , 2 },
        { FA , 2 },
        { SO , 2 },
        { MI , 4 },
        { NO_SOUND , 1 }
    };

    while(true){
         for(int i = 0 ; i < 13 ; i++ ){
             tone(13,freq[score[i][0]],200 * score[i][1]);
             delay(200 * score[i][1]);
         }
    }
}
