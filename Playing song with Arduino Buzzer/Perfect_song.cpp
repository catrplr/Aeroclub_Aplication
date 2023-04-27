//https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody

//power from pin 10

const int pin = 10;
  
// Defining frequency of each music note

#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988

// Music notes of the song, 0 is silence
//source : https://www.youtube.com/watch?v=8s30fgNbBis&ab_channel=Betacustic 
//noted the song in copy and transformed it into scientific pitch notation 

int notes[] = {
    0      , 0      ,0       ,     0   , 0,
    0      , 0      ,0       ,     0   , 0,
    NOTE_D4, NOTE_E4, NOTE_G4, NOTE_G4, 0,
    NOTE_B4, NOTE_A4, NOTE_G4, NOTE_B4, 0,
    
    NOTE_A4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_A4,NOTE_G4,NOTE_G4,0,
    NOTE_G4, NOTE_A4, NOTE_B4,NOTE_A4 ,0,
    NOTE_G4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_B4, 0,
    NOTE_D5, 0, NOTE_B4, NOTE_G4,NOTE_G4,NOTE_G4 ,0,
    
    NOTE_G4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C4,0,
    NOTE_C4, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_A4,NOTE_G4,0,
    NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, 0,NOTE_D4,
    NOTE_D4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_A4,NOTE_A4,
    
    NOTE_B5, 0, NOTE_B5, 0, NOTE_B5,0,NOTE_B5,0,
    NOTE_A4, 0, NOTE_G4, NOTE_B5, 0,NOTE_B5, 0,
    NOTE_B5, 0,NOTE_B5, 0, NOTE_A4, 0, NOTE_G4,
    0, NOTE_C5, 0, NOTE_B4, NOTE_A4,NOTE_G4,0,
    
    NOTE_D4, 0, NOTE_B5,0, NOTE_C5, NOTE_B5,NOTE_A5,0,
    NOTE_B5, NOTE_A5, NOTE_G5, NOTE_B5, 0,NOTE_B5, 0,
    NOTE_B5, 0, NOTE_B5, 0, NOTE_A5,0,NOTE_G4,
    NOTE_B5, 0, NOTE_B5, 0, NOTE_B5,0,NOTE_B5,
    
    0, NOTE_A4, 0, NOTE_G4, NOTE_C5,0,NOTE_B4,
  
};


// Durations of each notes(ms)


int durations[] = {
    250, 250, 250, 2000, 1000,
    250, 250, 250, 2000, 1000,
    250, 250, 250, 2000, 1000,
    250, 250, 250, 2000, 1000,
    
    250,250,250,250,250,250,1000,1000,
    250,250,250, 2000, 1000,
    250,250,250,250, 2000, 1000,
    500, 250,250, 500, 250, 1000, 1000,
    
    250,250,250,250, 500, 250,
    250,250,250,250,250,500,125,
    250,250,250,2000,250,250,
    250,250,250,250,250,250,250,
    
    750,250,750,250,750,250,250,
    250,250,250,750,250,750,250,
    750,250,250,250,250,250,250,
    125,500,250,500,250,750,250,
  
    750,250,750,250,250,500,250,
    250,250,250,750,250,750,250,
    750,250,250,250,250,250,250,
    750,250,750,250,750,250,250,
    
    250,250,750,250,500,250,250,
};

const float songSpeed = 1.0;

void setup()
{
  const int totalNotes = sizeof(notes) / sizeof(int);
  // Looping through each note
  for (int i = 0; i < totalNotes; i++)
      {
        const int currentNote = notes[i];
        float wait = durations[i] / songSpeed;
        if (currentNote != 0)
              {tone(pin, notes[i], wait);}
        else
              {noTone(pin);}
        delay(wait);
      }
}

void loop()
{
  // no need to repeat the melody.
}
