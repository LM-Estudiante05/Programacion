/*
Nombre: Luis Cabrera
*/
#include <stdio.h>

int main() {
    int estudiantes, asignaturas;

    printf("Sistema de gestión de calificaciones\n");
    printf("¿Cuántos estudiantes va a gestionar?: ");
    scanf("%d", &estudiantes);
    printf("\n¿Cuántas asignaturas van a ser calificadas?: ");
    scanf("%d", &asignaturas);

    float calificaciones[estudiantes][asignaturas];
    float promedioEst[estudiantes], promedioAsig[asignaturas];
    float maxEst[estudiantes], minEst[estudiantes];
    float maxAsig[asignaturas], minAsig[asignaturas];
    int aprobados[asignaturas], reprobados[asignaturas];
    char nomEstudiantes[estudiantes][20], nomAsignaturas[asignaturas][20];

    for (int i = 0; i < estudiantes; i++) {
        printf("\nIngrese el nombre del estudiante %d (máx 20 caracteres): ", i + 1);
        scanf("%s", nomEstudiantes[i]);
    }

    for (int j = 0; j < asignaturas; j++) {
        printf("\nIngrese el nombre de la asignatura %d (máx 20 caracteres): ", j + 1);
        scanf("%s", nomAsignaturas[j]);
    }

    for (int i = 0; i < estudiantes; i++) {
        for (int j = 0; j < asignaturas; j++) {
            do {
                printf("Ingrese la calificación de %s en %s (0–10): \n", 
                       nomEstudiantes[i], nomAsignaturas[j]);
                scanf("%f", &calificaciones[i][j]);
                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10)
                    printf("❌ Valor inválido. Intente de nuevo.\n");
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
        }
    }

    for (int i = 0; i < estudiantes; i++) {
        float suma = 0;
        maxEst[i] = calificaciones[i][0];
        minEst[i] = calificaciones[i][0];
        for (int j = 0; j < asignaturas; j++) {
            float nota = calificaciones[i][j];
            suma += nota;
            if (nota > maxEst[i]) maxEst[i] = nota;
            if (nota < minEst[i]) minEst[i] = nota;
        }
        promedioEst[i] = suma / asignaturas;
    }

    for (int j = 0; j < asignaturas; j++) {
        float suma = 0;
        maxAsig[j] = calificaciones[0][j];
        minAsig[j] = calificaciones[0][j];
        aprobados[j] = reprobados[j] = 0;
        for (int i = 0; i < estudiantes; i++) {
            float nota = calificaciones[i][j];
            suma += nota;
            if (nota > maxAsig[j]) maxAsig[j] = nota;
            if (nota < minAsig[j]) minAsig[j] = nota;
            if (nota >= 6) aprobados[j]++;
            else reprobados[j]++;
        }
        promedioAsig[j] = suma / estudiantes;
    }

    printf("\n===== Promedio por estudiante =====\n");
    for (int i = 0; i < estudiantes; i++) {
        printf("%-15s → Promedio: %.2f | Máx: %.2f | Mín: %.2f\n",
               nomEstudiantes[i], promedioEst[i], maxEst[i], minEst[i]);
    }

    printf("\n===== Promedio por asignatura =====\n");
    for (int j = 0; j < asignaturas; j++) {
        printf("%-15s → Promedio: %.2f | Máx: %.2f | Mín: %.2f | Aprobados: %d | Reprobados: %d\n",
               nomAsignaturas[j], promedioAsig[j], maxAsig[j], minAsig[j],
               aprobados[j], reprobados[j]);
    }

    return 0;
}