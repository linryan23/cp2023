#include <stdio.h>

int main() {
    // ��见����辣隞亙神�乩�滨宏��屸�笔漲�彍���
    FILE *outputFile = fopen("motion_data.txt", "w");
    if (!outputFile) {
        fprintf(stderr, "�⊥�訫肟撱箸彍��𡁏��辣��\n");
        return 1;
    }

    // 璅⊥挱�见�� 10 蝘雴蒂閮��𦯀�滨宏��屸�笔漲嚗��峕�撠�彍��𡁜神�交��辣
    double x = 0.2;  // ��嘥�衤�滨宏
    double v = 0.0;  // ��嘥�钅�笔漲
    double dt = 0.01; // ����𤘪郊�𩑈
    double t = 0.0;  // �����

    while (t <= 10.0) {
        double acceleration = (-10.0 * x - 0.5 * v) / 1.0; // �躰ㄐ靽格㺿鈭�蝟餌絞�����彍
        v += acceleration * dt;
        x += v * dt;

        fprintf(outputFile, "%lf %lf %lf\n", t, x, v);

        t += dt;
    }

    // ��𣈯�㗇彍��𡁏��辣
    fclose(outputFile);

    // 雿輻鍂popen��笔�柖nuplot�脩��
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (!gnuplotPipe) {
        fprintf(stderr, "�⊥�訫�笔�柖nuplot��\n");
        return 1;
    }

    // 雿輻鍂Gnuplot蝜芸�𡝗��誘嚗峕���𡁜�堒�𧢲��辣��諹撓�枂PNG
    fprintf(gnuplotPipe, "set terminal png font 'default,12' size 800,400\n");
    fprintf(gnuplotPipe, "set output './../images/motion_plot.png'\n");
    fprintf(gnuplotPipe, "set title 'displacement and velocity vs. time'\n");
    fprintf(gnuplotPipe, "set xlabel 'time (s)'\n");
    fprintf(gnuplotPipe, "set ylabel 'displacement (m)'\n");
    fprintf(gnuplotPipe, "plot 'motion_data.txt' using 1:2 with lines lw 2 title 'displacement', \
                             'motion_data.txt' using 1:3 with lines lw 2 title 'velocity'\n");

    // ��𣈯�滝nuplot�脩��
    fprintf(gnuplotPipe, "exit\n");
    pclose(gnuplotPipe);

    return 0;
}