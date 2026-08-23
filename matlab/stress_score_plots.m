data = readtable('C:\Users\ammed\OneDrive\Pictures\Documents\Projects\stress_monitor\cpp\stress_data.csv');

%extract data
stress = data.Stress_Score;
smoothStress = smoothdata(stress);

%plot stress score (raw and smoothed)
figure;
plot(stress, 'Color', [0.5 0 0.8]); hold on;
plot(smoothStress, 'LineWidth', 2, 'Color', [0 0.6 1]);
title('Stress Score: Raw vs Smoothed');
xlabel('Samples');
ylabel('Stress Score');
legend('Raw', 'Smoothed');

%plot stress score fft
Y = fft(stress);
L = length(stress);
P2 = abs(Y/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);
f = (0:(L/2))/L;

figure;
plot(f, P1);
title('Stress Score FFT');
xlabel('Frequency');
ylabel('Magnitude');

%plot CPU load vs. stress score, individual data
cpu = data.CPU_Raw;

figure;
scatter(cpu, stress, 'filled');
title('CPU Load vs Stress Score');
xlabel('CPU Percent');
ylabel('Stress Score');
