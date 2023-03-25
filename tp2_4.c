#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int velocidad; //entre 1 y 3 GHz
    int anio; //entre 2015 y 2023
    int cantidad; //entre 1 y 8
    int tipo_cpu; //índice del arreglo tipos
} pc;

void cargar(pc *nueva) {
    int tipo;
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    puts("Ingrese el anio de la PC: ");
    scanf("%d", &nueva->anio);
    puts("Ingrese la velocidad del procesador: ");
    scanf("%d", &nueva->velocidad);
    puts("Ingrese cantidad de nucleos: ");
    scanf("%d", &nueva->cantidad);
    puts("Ingrese el tipo de procesador: 1)Intel 2)AMD 3)Celeron 4)Athlon 5)Core 6)Pentium");
    scanf("%d", &tipo);
    nueva->tipo_cpu = tipo - 1;
}

void mostrar(pc *nueva) {
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    printf("\nAnio: %d\n", nueva->anio);
    printf("Velocidad del procesador: %d\n", nueva->velocidad);
    printf("Cantidad de nucleos: %d\n", nueva->cantidad);
    printf("Tipo de procesador: %s\n", tipos[nueva->tipo_cpu]);
}

void mostrarPcMasVieja(pc *nueva, int tama){
    int MasVieja = 30000;
    pc *pcMasVieja; // variable para almacenar la dirección de la PC más antigua
    for (int i = 0; i < tama; i++)
    {
        if (nueva->anio < MasVieja)
        {
            MasVieja = nueva->anio;
            pcMasVieja = nueva; // actualiza la dirección de la PC más antigua
        }
        nueva++;

    }

    puts("La PC mas antigua es:");
    mostrar(pcMasVieja); // muestra la información de la PC más antigua
    
}
void pcMasRapida(pc *nueva,int tama){
   int masRapida = 0;
   pc *pcMasRapida;
   for (int i = 0; i < tama; i++)
   {
     if (nueva->velocidad > masRapida)
     {
        pcMasRapida = nueva;
        masRapida = nueva->velocidad;
     }
     nueva++;
   }
   puts("la pc mas rapida es:");
   mostrar(pcMasRapida);

}

int main() {
    pc *mi_pc;
    int tama = 5;
    mi_pc = malloc(tama * sizeof(pc));
    for (int i = 0; i < tama; i++)
    {
         cargar(mi_pc);
         mi_pc++;
    }
    mi_pc = mi_pc - tama;//regreso a la posicion de memoria correcta
    
   
    mostrarPcMasVieja(mi_pc,tama);
    pcMasRapida(mi_pc,tama);
    free(mi_pc);
    return 0;
}