#include <stdio.h>
#include <stdlib.h>

struct NameRecord{
    char name[31];
    int year;
    int frequency;
};

void allCaps(char search[]){
	int i=0;
	for(i=0; i < 31; i++){
		search[i] = toupper(search[i]);
	}
//	printf("%s", search);  //THIS IS FOR TESTING----
}

int getRawData(FILE *fp, struct NameRecord records[],long currSize){
    
    while(fscanf(fp,"%d,%[^,],%d\n", &records[currSize].year, records[currSize].name, &records[currSize].frequency) != EOF){
    currSize++;
    }
/* THIS AREA IF FOR TESTIONG---- 
    for(x=0; x < 5; x++){
        printf("Year is %d\n", records[x].year);
        printf("Name is %s\n", records[x].name);
        printf("Frequency is %d\n\n", records[x].frequency);
    }
*/
return currSize;
}


void setYearTotals(struct NameRecord records[], long size, long YearRangeTotal[]){
    long i;

    for(i=0; i <= size; i++){
        if( records[i].year >= 1921 && records[i].year <= 1925){
            YearRangeTotal[0] = YearRangeTotal[0] + records[i].frequency;
        }else if( records[i].year >= 1926 && records[i].year <= 1930){
            YearRangeTotal[1] = YearRangeTotal[1] + records[i].frequency;
        }else if( records[i].year >= 1931 && records[i].year <= 1935){
            YearRangeTotal[2] = YearRangeTotal[2] + records[i].frequency;
        }else if( records[i].year >= 1936 && records[i].year <= 1940){
            YearRangeTotal[3] = YearRangeTotal[3] + records[i].frequency;
        }else if( records[i].year >= 1941 && records[i].year <= 1945){
            YearRangeTotal[4] = YearRangeTotal[4] + records[i].frequency;
        }else if( records[i].year >= 1946 && records[i].year <= 1950){
            YearRangeTotal[5] = YearRangeTotal[5] + records[i].frequency;
        }else if( records[i].year >= 1951 && records[i].year <= 1955){
            YearRangeTotal[6] = YearRangeTotal[6] + records[i].frequency;
        }else if( records[i].year >= 1956 && records[i].year <= 1960){
            YearRangeTotal[7] = YearRangeTotal[7] + records[i].frequency;
        }else if( records[i].year >= 1961 && records[i].year <= 1965){
            YearRangeTotal[8] = YearRangeTotal[8] + records[i].frequency;
        }else if( records[i].year >= 1966 && records[i].year <= 1970){
            YearRangeTotal[9] = YearRangeTotal[9] + records[i].frequency;
        }else if( records[i].year >= 1971 && records[i].year <= 1975){
            YearRangeTotal[10] = YearRangeTotal[10] + records[i].frequency;
        }else if( records[i].year >= 1976 && records[i].year <= 1980){
            YearRangeTotal[11] = YearRangeTotal[11] + records[i].frequency;
        }else if( records[i].year >= 1981 && records[i].year <= 1985){
            YearRangeTotal[12] = YearRangeTotal[12] + records[i].frequency;
        }else if( records[i].year >= 1986 && records[i].year <= 1990){
            YearRangeTotal[13] = YearRangeTotal[13] + records[i].frequency;
        }else if( records[i].year >= 1991 && records[i].year <= 1995){
            YearRangeTotal[14] = YearRangeTotal[14] + records[i].frequency;
        }else if( records[i].year >= 1996 && records[i].year <= 2000){
            YearRangeTotal[15] = YearRangeTotal[15] + records[i].frequency;
        }else if( records[i].year >= 2001 && records[i].year <= 2005){
            YearRangeTotal[16] = YearRangeTotal[16] + records[i].frequency;
        }else if( records[i].year >= 2006 && records[i].year <= 2010){
            YearRangeTotal[17] = YearRangeTotal[17] + records[i].frequency;
        }
    } 
}

void setNameYearTotal(char thename[], struct NameRecord records[], long size, int nameTotal[]){
    long i;
    for(i=0; i < size; i++){
        if(records[i].year >= 1921 && records[i].year <= 1925){
            if( strcmp(thename,records[i].name) == 0)
                nameTotal[0] = nameTotal[0] + records[i].frequency;
        }else if( records[i].year >= 1926 && records[i].year <= 1930){
            if( strcmp(thename,records[i].name) == 0)
                nameTotal[1] = nameTotal[1] + records[i].frequency;
        }else if( records[i].year >= 1931 && records[i].year <= 1935){
            if( strcmp(thename,records[i].name) == 0)
                nameTotal[2] = nameTotal[2] + records[i].frequency;
        }else if( records[i].year >= 1936 && records[i].year <= 1940){
            if( strcmp(thename,records[i].name) == 0)
                nameTotal[3] = nameTotal[3] + records[i].frequency;
        }else if( records[i].year >= 1941 && records[i].year <= 1945){
            if( strcmp(thename,records[i].name) == 0)
                nameTotal[4] = nameTotal[4] + records[i].frequency;
        }else if( records[i].year >= 1946 && records[i].year <= 1950){
            if( strcmp(thename,records[i].name) == 0)
                nameTotal[5] = nameTotal[5] + records[i].frequency;
        }else if( records[i].year >= 1951 && records[i].year <= 1955){
            if( strcmp(thename,records[i].name) == 0)
                nameTotal[6] = nameTotal[6] + records[i].frequency;
        }else if( records[i].year >= 1956 && records[i].year <= 1960){
            if( strcmp(thename,records[i].name) == 0)
                nameTotal[7] = nameTotal[7] + records[i].frequency;
        }else if( records[i].year >= 1961 && records[i].year <= 1965){
            if( strcmp(thename,records[i].name) == 0)
                nameTotal[8] = nameTotal[8] + records[i].frequency;
        }else if( records[i].year >= 1966 && records[i].year <= 1970){
            if( strcmp(thename,records[i].name) == 0)
                nameTotal[9] = nameTotal[9] + records[i].frequency;
        }else if( records[i].year >= 1971 && records[i].year <= 1975){
            if( strcmp(thename,records[i].name) == 0)
                nameTotal[10] = nameTotal[10] + records[i].frequency;
        }else if( records[i].year >= 1976 && records[i].year <= 1980){
            if( strcmp(thename,records[i].name) == 0)
                nameTotal[11] = nameTotal[11] + records[i].frequency;
        }else if( records[i].year >= 1981 && records[i].year <= 1985){
            if( strcmp(thename,records[i].name) == 0)
                nameTotal[12] = nameTotal[12] + records[i].frequency;
        }else if( records[i].year >= 1986 && records[i].year <= 1990){
            if( strcmp(thename,records[i].name) == 0)
                nameTotal[13] = nameTotal[13] + records[i].frequency;
        }else if( records[i].year >= 1991 && records[i].year <= 1995){
            if( strcmp(thename,records[i].name) == 0)
                nameTotal[14] = nameTotal[14] + records[i].frequency;
        }else if( records[i].year >= 1996 && records[i].year <= 2000){
            if( strcmp(thename,records[i].name) == 0)
                nameTotal[15] = nameTotal[15] + records[i].frequency;
        }else if( records[i].year >= 2001 && records[i].year <= 2005){
            if( strcmp(thename,records[i].name) == 0)
                nameTotal[16] = nameTotal[16] + records[i].frequency;
        }else if( records[i].year >= 2006 && records[i].year <= 2010){
            if( strcmp(thename,records[i].name) == 0)
                nameTotal[17] = nameTotal[17] + records[i].frequency;
        }
    }
}

void getperHundredThousand(int nameTotal[],long YearRangeTotal[],double perHundredThousand[]){
  int i;
    
  for(i=0; i < 18; i++){
        perHundredThousand[i] = 100000 *(1.0 * nameTotal[i]) / (1.0 * YearRangeTotal[i]); 
    }
}

void printData(double perHundredThousand[]){
    int i;
    int start = 1921;
    int end = 1925;

    for(i=0; i < 18; i++){
        printf("%d - %d: %.2lf\n",start,end,perHundredThousand[i]); 
        start += 5;
        end += 5;
    }
}

void graphPerHundredThousand(double perHundredThousand[]){
    
    double sort[18];
    int i, j; 
    double temp;
    double smallest_no;
    int m;
    int start = 2006;
    int end = 2010;
    double stars = 0;
    int total_stars = 0;

    for(i=0; i < 18; i++){
        sort[i] = perHundredThousand[i];    
    }

    for(i=0; i < 17; i++){
        for(j= i + 1; j <= 18; j++){
           if(sort[i] > sort[j]){
                temp = sort[i];
                sort[i] = sort[j];
                sort[j] = temp;
            }
        }
    }
    for(m=0; m < 18; m++){
        if(sort[m] > 0){
            smallest_no = sort[m];
            break; 
        }
    }
printf("The smallest no is %.2lf\n", smallest_no);
 
    for(m=17; m >= 0; m--){
       stars = perHundredThousand[m] / smallest_no;
       total_stars = stars;
       if(total_stars < stars && stars > 0.01){
           total_stars++;
       }
        printf("%d - %d  | ",start,end);
            for(i=1; i <= total_stars; i++){
                printf("*");
            }
            printf("\n");
        start -= 5;
        end -= 5;
    }

}

void main()
{
    struct NameRecord records[150000];
	long year_range[18];
    int nameTotal[18];
    char usr_ent[31];
	FILE *males;
	FILE *females;
	long total_names = 0;
    int i;
    double hun_tho[18];
    int start = 1921;
    int end = 1925;

    printf("Enter a name to search: ");
    gets(usr_ent);
    allCaps(usr_ent);
	
    if((males = fopen("names_males.csv","r")) != NULL){
	    total_names = getRawData(males, records, total_names);
	}
    fclose(males);

    if((females = fopen("names_females.csv","r")) != NULL){
        total_names = getRawData(females, records, total_names);
    }
    fclose(females);
    setYearTotals(records,150000, year_range); 
    setNameYearTotal(usr_ent, records, 150000, nameTotal); 
    getperHundredThousand(nameTotal, year_range, hun_tho);
printf("Number of Babies named %s per 100,000 births\n", usr_ent);
printf("=================================================\n");
    printData(hun_tho);
    graphPerHundredThousand(hun_tho);

/* Testing commands */
// printf("You've have entered : %s\n", name);
//printf("There are total %d names\n", total_names);

/*
   for(i=0; i < 18; i++){
printf("There are %d names in %d to %d\n", nameTotal[i],start,end);
    start = start +5;
    end = end + 5;
} 
start = 1921;
end = 1925;

for(i=0; i < 18; i++){
    printf("There are %ld numbers of name in between %d to %d\n",
            year_range[i],start,end);
    start = start +5;
    end = end + 5;
}
*/
}
