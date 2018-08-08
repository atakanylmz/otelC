#include <stdio.h>
#include <stdlib.h>

int main()
{
    //  3mevsim*12hafta*100oda=3600kapasite

    int oda[100][12][3];
    int i,bosalt,sayac,hafta,musait,say,no,odakisisi,ek,musteri;
    char mevsim,tip,tur;
    float ucret;
    for(i=0; i<3; i++)
    {
        for(hafta=0; hafta<12; hafta++)
        {
            for(bosalt=0; bosalt<100; bosalt++)
            {
                oda[bosalt][hafta][i]=0;
            }
        }
    }
    for(musteri=0; musteri<3600; musteri++)
    {
        printf("\nHangi mevsimde konaklama yapmak istersiniz:\n");
        printf("\nSonbahar icin 'S', Bahar icin 'B', Yaz icin 'Y' tusuna basiniz:\n");
        scanf("%s",&mevsim);
        switch(mevsim)
        {
        case 'S':
            printf("\nSonbahar mevsiminin kacinci haftasinda konaklama yapmak istersiniz:");
            scanf("%d",&hafta);
            i=0;
            while(hafta>12||hafta<1)
            {
                if(i==2)
                {
                    printf("\n3 defa yanlis giris yaptiginiz icin program sonlandi.");
                    return 0;
                }
                else
                {
                    printf("\nyanlis giris yaptiniz, 1-12 aralginda giris yapiniz:");
                    scanf("%d",&hafta);
                }
                i++;
            }
            printf("\nLutfen oda tipini seciniz:\n");
            printf("Standart oda icin'S', Deluxe oda icin 'D', Large Deluxe oda icin 'L' kodunu giriniz:");
            scanf("%s",&tip);
            printf("\n\n");
            switch(tip)
            {
            case 'S':
                for(musait=0; musait<100; musait=musait+2)
                {
                    if(oda[musait][hafta][0]==0)
                    {
                        printf("%d---",musait+1);
                    }
                }
                printf(" nolu odalar standart odalara dahildir, birini seciniz:");
                scanf("%d",&no);
                while(oda[no-1][hafta][0]==1)
                {
                    printf("\ndolu oda sectiniz, yeni oda seciniz");
                    scanf("%d",&no);
                }
                oda[no-1][hafta][0]=1;
                printf("\nodada kalacak kisi sayisini giriniz:");
                scanf("%d",&odakisisi);
                if(odakisisi>4)
                {
                    printf("\nodalar 4 kisilik oldugu icin ");
                    i=0;
                    printf("\n\n");
                    for(musait=0; musait<100; musait=musait+2)
                    {
                        if(oda[musait][hafta][0]==0)
                        {
                            printf("%d---",musait+1);
                            i++;
                        }
                    }
                    printf("\nodalari arasindan bir oda daha seciniz:");
                    scanf("%d",&ek);
                    oda[ek-1][hafta][0]=1;
                }
                printf("\nrezervasyon turunu seciniz:");
                printf("\nOn odemeli icin 'O', Havale ile odeme icin 'H', Standart odeme icin 'S' kodunu giriniz:");
                scanf("%s",&tur);
                switch(tur)
                {
                case 'O':
                    ucret=0.85*odakisisi*25;
                    break;
                case 'H':
                    if(odakisisi>5)
                    {
                        ucret=(odakisisi-1)*25+25*0.25;
                    }
                    else if(odakisisi>3)
                    {
                        ucret=(odakisisi-1)*25+25*0.5;
                    }
                    else
                    {
                        ucret=odakisisi*25;
                    }
                    break;
                case 'S':
                    ucret=odakisisi*25;
                    break;
                default:
                    break;
                    //standart oda sonbahar sonu
                }//on odeme turunun sonu sonbahar
                break;
            case 'D':
                printf("\n\n");
                for(musait=0; musait<16; musait++)
                {
                    if(oda[6*musait+5][hafta][0]==0)
                    {
                        printf("%d---",6*musait+6);
                    }
                }
                printf("\t nolu odalar DELUXE odalara dahildir, birini seciniz:");
                scanf("%d",&no);
                while(oda[no-1][hafta][0]==1)
                {
                    printf("\ndolu oda sectiniz, yeni oda seciniz");
                    scanf("%d",&no);
                }
                oda[no-1][hafta][0]=1;
                printf("\nodada kalacak kisi sayisini giriniz:");
                scanf("%d",&odakisisi);
                if(odakisisi>4)
                {
                    printf("\nodalar 4 kisilik oldugu icin ");
                    i=0;
                    for(musait=0; musait<16; musait++)
                    {
                        if(oda[6*musait+5][hafta][0]==0)
                        {
                            printf("%d---",6*musait+6);
                        }
                    }
                    printf("\nodalari arasindan bir oda daha seciniz:");
                    scanf("%d",&ek);
                    oda[ek-1][hafta][0]=1;
                }
                printf("\nrezervasyon turunu seciniz:");
                printf("\nOn odemeli icin 'O', Havale ile odeme icin 'H', Standart odeme icin 'S' kodunu giriniz:");
                scanf("%s",&tur);
                switch(tur)
                {
                case 'O':
                    ucret=0.85*odakisisi*50;
                    break;
                case 'H':
                    if(odakisisi>5)
                    {
                        ucret=(odakisisi-1)*50+50*0.25;
                    }
                    else if(odakisisi>3)
                    {
                        ucret=(odakisisi-1)*50+50*0.5;
                    }
                    else
                    {
                        ucret=odakisisi*50;
                    }
                    break;
                case 'S':
                    ucret=odakisisi*50;
                    break;
                default:
                    break;
                }//deluxe oda sonbahar sonu
                break;
            case 'L':
                printf("\n\n");
                for(i=1; i<100; i+=2)
                {
                    if((i+1)%6==0)
                    {
                        continue;
                    }
                    else
                    {
                        if(oda[i][hafta][0]==0)
                        {
                            printf("%d---",i+1);
                        }
                    }
                }
                printf("\t nolu odalar DELUXE odalara dahildir, birini seciniz:");
                scanf("%d",&no);
                while(oda[no-1][hafta][0]==1)
                {
                    printf("\ndolu oda sectiniz, yeni oda seciniz");
                    scanf("%d",&no);
                }
                oda[no-1][hafta][0]=1;
                printf("\nodada kalacak kisi sayisini giriniz:");
                scanf("%d",&odakisisi);
                if(odakisisi>7)
                {
                    printf("\nodalar 7 kisilik oldugu icin ");
                    for(i=1; i<100; i+=2)
                    {
                        if((i+1)%6==0)
                        {
                            continue;
                        }
                        else
                        {
                            if(oda[i][hafta][0]==0)
                            {
                                printf("%d---",i+1);
                            }
                        }
                    }
                    printf("\nodalari arasindan bir oda daha seciniz:");
                    scanf("%d",&ek);
                    oda[ek-1][hafta][0]=1;
                }
                printf("\nrezervasyon turunu seciniz:");
                printf("\nOn odemeli icin 'O', Havale ile odeme icin 'H', Standart odeme icin 'S' kodunu giriniz:");
                scanf("%s",&tur);
                if(odakisisi<=7)
                    ucret=250.0;
                else
                    ucret=500.0;
                switch(tur)
                {
                case 'O':
                case 'H':
                case 'S':
                    break;
                default:
                    break;
                }//large deluxe oda sonbahar sonu
                break;
            default:
                break;
            }//sonbahar mevsiminin sonu
            sayac=0;
            for(say=0; say<100; say++)
            {
                if(oda[say][hafta][0]==1)
                    sayac++;
            }
            break;
        case 'B':
            printf("\nBahar mevsiminin kacinci haftasinda konaklama yapmak istersiniz:");
            scanf("%d",&hafta);
            i=0;
            while(hafta>12||hafta<1)
            {
                if(i==2)
                {
                    printf("\n3 defa yanlis giris yaptiginiz icin program sonlandi.");
                    return 0;
                }
                else
                {
                    printf("\nyanlis giris yaptiniz, 1-12 aralginda giris yapiniz:");
                    scanf("%d",&hafta);
                }
                i++;
            }
            printf("\nLutfen oda tipini seciniz:\n");
            printf("\nStandart oda icin'S', Deluxe oda icin 'D', Large Deluxe oda icin 'L' kodunu giriniz:");
            scanf("%s",&tip);
            printf("\n\n");
            switch(tip)
            {
            case 'S':
                for(musait=0; musait<100; musait=musait+2)
                {
                    if(oda[musait][hafta][1]==0)
                    {
                        printf("%d---",musait+1);
                    }
                }
                printf(" nolu odalar standart odalara dahildir, birini seciniz:");
                scanf("%d",&no);
                while(oda[no-1][hafta][1]==1)
                {
                    printf("\ndolu oda sectiniz, yeni oda seciniz");
                    scanf("%d",&no);
                }
                oda[no-1][hafta][1]=1;
                printf("\nodada kalacak kisi sayisini giriniz:");
                scanf("%d",&odakisisi);
                if(odakisisi>4)
                {
                    printf("\nodalar 4 kisilik oldugu icin ");
                    i=0;
                    printf("\n\n");
                    for(musait=0; musait<100; musait=musait+2)
                    {
                        if(oda[musait][hafta][1]==0)
                        {
                            printf("%d---",musait+1);
                            i++;
                        }
                    }
                    printf("\nodalari arasindan bir oda daha seciniz:");
                    scanf("%d",&ek);
                    oda[ek-1][hafta][1]=1;
                }
                printf("\nrezervasyon turunu seciniz:");
                printf("\nOn odemeli icin 'O', Havale ile odeme icin 'H', Standart odeme icin 'S' kodunu giriniz:");
                scanf("%s",&tur);
                switch(tur)
                {
                case 'O':
                    ucret=0.85*odakisisi*40;
                    break;
                case 'H':
                    if(odakisisi>5)
                    {
                        ucret=(odakisisi-1)*40+40*0.25;
                    }
                    else if(odakisisi>3)
                    {
                        ucret=(odakisisi-1)*40+40*0.5;
                    }
                    else
                    {
                        ucret=odakisisi*40;
                    }
                    break;
                case 'S':
                    ucret=odakisisi*40;
                    break;
                default:
                    break;
                    //standart oda sonbahar sonu
                }//on odeme turunun sonu sonbahar
                break;
            case 'D':
                printf("\n\n");
                for(musait=0; musait<16; musait++)
                {
                    if(oda[6*musait+5][hafta][1]==0)
                    {
                        printf("%d---",6*musait+6);
                    }
                }
                printf("\t nolu odalar DELUXE odalara dahildir, birini seciniz:");
                scanf("%d",&no);
                while(oda[no-1][hafta][1]==1)
                {
                    printf("\ndolu oda sectiniz, yeni oda seciniz");
                    scanf("%d",&no);
                }
                oda[no-1][hafta][1]=1;
                printf("\nodada kalacak kisi sayisini giriniz:");
                scanf("%d",&odakisisi);
                if(odakisisi>4)
                {
                    printf("\nodalar 4 kisilik oldugu icin ");
                    i=0;
                    for(musait=0; musait<16; musait++)
                    {
                        if(oda[6*musait+5][hafta][1]==0)
                        {
                            printf("%d---",6*musait+6);
                        }
                    }
                    printf("\nodalari arasindan bir oda daha seciniz:");
                    scanf("%d",&ek);
                    oda[ek-1][hafta][1]=1;
                }
                printf("\nrezervasyon turunu seciniz:");
                printf("\nOn odemeli icin 'O', Havale ile odeme icin 'H', Standart odeme icin 'S' kodunu giriniz:");
                scanf("%s",&tur);
                switch(tur)
                {
                case 'O':
                    ucret=0.85*odakisisi*75;
                    break;
                case 'H':
                    if(odakisisi>5)
                    {
                        ucret=(odakisisi-1)*75+75*0.25;
                    }
                    else if(odakisisi>3)
                    {
                        ucret=(odakisisi-1)*75+75*0.5;
                    }
                    else
                    {
                        ucret=odakisisi*75;
                    }
                    break;
                case 'S':
                    ucret=odakisisi*75;
                    break;
                default:
                    break;
                }//deluxe oda sonbahar sonu
                break;
            case 'L':
                printf("\n\n");
                for(i=1; i<100; i+=2)
                {
                    if((i+1)%6==0)
                    {
                        continue;
                    }
                    else
                    {
                        if(oda[i][hafta][1]==0)
                        {
                            printf("%d---",i+1);
                        }
                    }
                }
                printf("\t nolu odalar DELUXE odalara dahildir, birini seciniz:");
                scanf("%d",&no);
                while(oda[no-1][hafta][1]==1)
                {
                    printf("\ndolu oda sectiniz, yeni oda seciniz");
                    scanf("%d",&no);
                }
                oda[no-1][hafta][1]=1;
                printf("\nodada kalacak kisi sayisini giriniz:");
                scanf("%d",&odakisisi);
                if(odakisisi>7)
                {
                    printf("\nodalar 7 kisilik oldugu icin ");
                    for(i=1; i<100; i+=2)
                    {
                        if((i+1)%6==0)
                        {
                            continue;
                        }
                        else
                        {
                            if(oda[i][hafta][1]==0)
                            {
                                printf("%d---",i+1);
                            }
                        }
                    }
                    printf("\nodalari arasindan bir oda daha seciniz:");
                    scanf("%d",&ek);
                    oda[ek-1][hafta][1]=1;
                }
                printf("\nrezervasyon turunu seciniz:");
                printf("\nOn odemeli icin 'O', Havale ile odeme icin 'H', Standart odeme icin 'S' kodunu giriniz:");
                scanf("%s",&tur);
                if(odakisisi<=7)
                    ucret=300.0;
                else
                    ucret=600.0;
                switch(tur)
                {
                case 'O':
                case 'H':
                case 'S':
                    break;
                default:
                    break;
                }//large deluxe oda sonbahar sonu
            default:
                break;
            }//sonbahar mevsiminin sonu
            sayac=0;
            for(say=0; say<100; say++)
            {
                if(oda[say][hafta][1]==1)
                    sayac++;
            }
            break;
        case 'Y':
            printf("\nYaz mevsiminin kacinci haftasinda konaklama yapmak istersiniz:");
            scanf("%d",&hafta);
            i=0;
            while(hafta>12||hafta<1)
            {
                if(i==2)
                {
                    printf("\n3 defa yanlis giris yaptiginiz icin program sonlandi.");
                    return 0;
                }
                else
                {
                    printf("\nyanlis giris yaptiniz, 1-12 aralginda giris yapiniz:");
                    scanf("%d",&hafta);
                }
                i++;
            }
            printf("\nLutfen oda tipini seciniz:\n");
            printf("Standart oda icin'S', Deluxe oda icin 'D', Large Deluxe oda icin 'L' kodunu giriniz:");
            scanf("%s",&tip);
            printf("\n\n");
            switch(tip)
            {
            case 'S':
                for(musait=0; musait<100; musait=musait+2)
                {
                    if(oda[musait][hafta][2]==0)
                    {
                        printf("%d---",musait+1);
                    }
                }
                printf(" nolu odalar standart odalara dahildir, birini seciniz:");
                scanf("%d",&no);
                while(oda[no-1][hafta][2]==1)
                {
                    printf("\ndolu oda sectiniz, yeni oda seciniz");
                    scanf("%d",&no);
                }
                oda[no-1][hafta][2]=1;
                printf("\nodada kalacak kisi sayisini giriniz:");
                scanf("%d",&odakisisi);
                if(odakisisi>4)
                {
                    printf("\nodalar 4 kisilik oldugu icin ");
                    i=0;
                    printf("\n\n");
                    for(musait=0; musait<100; musait=musait+2)
                    {
                        if(oda[musait][hafta][2]==0)
                        {
                            printf("%d---",musait+1);
                            i++;
                        }
                    }
                    printf("\nodalari arasindan bir oda daha seciniz:");
                    scanf("%d",&ek);
                    oda[ek-1][hafta][2]=1;
                }
                printf("\nrezervasyon turunu seciniz:");
                printf("\nOn odemeli icin 'O', Havale ile odeme icin 'H', Standart odeme icin 'S' kodunu giriniz:");
                scanf("%s",&tur);
                switch(tur)
                {
                case 'O':
                    ucret=0.85*odakisisi*60;
                    break;
                case 'H':
                    if(odakisisi>5)
                    {
                        ucret=(odakisisi-1)*60+60*0.25;
                    }
                    else if(odakisisi>3)
                    {
                        ucret=(odakisisi-1)*60+60*0.5;
                    }
                    else
                    {
                        ucret=odakisisi*60;
                    }
                    break;
                case 'S':
                    ucret=odakisisi*60;
                    break;
                default:
                    break;
                    //standart oda sonbahar sonu
                }//on odeme turunun sonu sonbahar
                break;
            case 'D':
                printf("\n\n");
                for(musait=0; musait<16; musait++)
                {
                    if(oda[6*musait+5][hafta][2]==0)
                    {
                        printf("%d---",6*musait+6);
                    }
                }
                printf("\t nolu odalar DELUXE odalara dahildir, birini seciniz:");
                scanf("%d",&no);
                while(oda[no-1][hafta][2]==1)
                {
                    printf("\ndolu oda sectiniz, yeni oda seciniz");
                    scanf("%d",&no);
                }
                oda[no-1][hafta][2]=1;
                printf("\nodada kalacak kisi sayisini giriniz:");
                scanf("%d",&odakisisi);
                if(odakisisi>4)
                {
                    printf("\nodalar 4 kisilik oldugu icin ");
                    i=0;
                    for(musait=0; musait<16; musait++)
                    {
                        if(oda[6*musait+5][hafta][2]==0)
                        {
                            printf("%d---",6*musait+6);
                        }
                    }
                    printf("\nodalari arasindan bir oda daha seciniz:");
                    scanf("%d",&ek);
                    oda[ek-1][hafta][2]=1;
                }
                printf("\nrezervasyon turunu seciniz:");
                printf("\nOn odemeli icin 'O', Havale ile odeme icin 'H', Standart odeme icin 'S' kodunu giriniz:");
                scanf("%s",&tur);
                switch(tur)
                {
                case 'O':
                    ucret=0.85*odakisisi*90;
                    break;
                case 'H':
                    if(odakisisi>5)
                    {
                        ucret=(odakisisi-1)*90+90*0.25;
                    }
                    else if(odakisisi>3)
                    {
                        ucret=(odakisisi-1)*90+90*0.5;
                    }
                    else
                    {
                        ucret=odakisisi*90;
                    }
                    break;
                case 'S':
                    ucret=odakisisi*90;
                    break;
                default:
                    break;
                }//deluxe oda sonbahar sonu
                break;
            case 'L':
                printf("\n\n");
                for(i=1; i<100; i+=2)
                {
                    if((i+1)%6==0)
                    {
                        continue;
                    }
                    else
                    {
                        if(oda[i][hafta][2]==0)
                        {
                            printf("%d---",i+1);
                        }
                    }
                }
                printf("\t nolu odalar DELUXE odalara dahildir, birini seciniz:");
                scanf("%d",&no);
                while(oda[no-1][hafta][2]==1)
                {
                    printf("\ndolu oda sectiniz, yeni oda seciniz");
                    scanf("%d",&no);
                }
                oda[no-1][hafta][2]=1;
                printf("\nodada kalacak kisi sayisini giriniz:");
                scanf("%d",&odakisisi);
                if(odakisisi>7)
                {
                    printf("\nodalar 7 kisilik oldugu icin ");
                    for(i=1; i<100; i+=2)
                    {
                        if((i+1)%6==0)
                        {
                            continue;
                        }
                        else
                        {
                            if(oda[i][hafta][2]==0)
                            {
                                printf("%d---",i+1);
                            }
                        }
                    }
                    printf("\nodalari arasindan bir oda daha seciniz:");
                    scanf("%d",&ek);
                    oda[ek-1][hafta][2]=1;
                }
                printf("\nrezervasyon turunu seciniz:");
                printf("\nOn odemeli icin 'O', Havale ile odeme icin 'H', Standart odeme icin 'S' kodunu giriniz:");
                scanf("%s",&tur);
                if(odakisisi<=7)
                    ucret=400.0;
                else
                    ucret=800.0;
                switch(tur)
                {
                case 'O':
                case 'H':
                case 'S':
                    break;
                default:
                    break;
                }//large deluxe oda sonbahar sonu
            default:
                break;
            }//sonbahar mevsiminin sonu
            sayac=0;
            for(say=0; say<100; say++)
            {
                if(oda[say][hafta][2]==1)
                    sayac++;
            }
            break;
        default:
            break;
        }//mevsimin sonu
        printf("\n\nbu hafta odalarin yuzde %d si doludur\n",sayac);
        printf("Odenecek ucret %.2f$'dir",ucret);
        printf("\nyeni rezervasyon girmek istiyorsaniz 'E'ye cikis icin herhangi bir tusa basiniz:");
        char yeni;
        scanf("%s",&yeni);
        if(yeni=='E')
            continue;
        else
            break;
    }//yeni musteriye geciyoruz
    return 0;
}
