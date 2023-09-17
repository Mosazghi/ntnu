s = tf('s');
K = 0.92;
T = 0.46;

h_ry = K/(1+T*s);

figure;
step(h_ry);
bode(h_ry)


