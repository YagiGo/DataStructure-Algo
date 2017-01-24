typedef enum {A,B,C,D,E} SchoolName;
typedef enum {MALE,FEMALE} Gender;
typedef struct
{
	char event;
	SchoolName school;
	Gender gender;
	int score;
} Individual;
typedef struct 
{
	int FemaleScore;
	int MaleScore;
	int TeamScore;
} Scores;
Individual report[n];
Scores result[4];
for(i = 0; i < n; i ++)
{
	switch(report[i].school)
	{
		case A:
			result[0].TeamScore +=report[i].score;
			switch(report[i].gender)
			{
				case MALE: result[0].MaleScore += report[i].score;
				case FEMALE: result[0].FemaleScore += report[i].score;
			} 
		case B:
			result[1].TeamScore +=report[i].score;
			switch(report[i].gender)
			{
				case MALE: result[1].MaleScore += report[i].score;
				case FEMALE: result[1].FemaleScore += report[i].score;
			} 
		case C:
			result[2].TeamScore +=report[i].score;
			switch(report[i].gender)
			{
				case MALE: result[2].MaleScore += report[i].score;
				case FEMALE: result[2].FemaleScore += report[i].score;
			} 
		case D:
			result[3].TeamScore +=report[i].score;
			switch(report[i].gender)
			{
				case MALE: result[3].MaleScore += report[i].score;
				case FEMALE: result[3].FemaleScore += report[i].score;
			} 
		case E:
			result[4].TeamScore +=report[i].score;
			switch(report[i].gender)
			{
				case MALE: result[4].MaleScore += report[i].score;
				case FEMALE: result[4].FemaleScore += report[i].score;
			} 
	}
}