Q: What is the number of significant lines that should be kept?
A: By looking at the 'edges.png' image, I may judge that 5 significant lines should be kept. However, after implement Hough Transform, I found there are 16 significant lines should be kept. Maybe the resolution of the Hough array is not high enough, so I also found some pretty close lines.

Q: What is the threshold value that should be used?
A: The threshold value I used here is 138.

Q: A sketch (by hand or by computer) of the most significant lines that were found, along with the (rho, theta) values for those lines.
A: The detected lines can be seen by running 'homework2.m' in MATLAB.
The (rho, theta) values for these lines in 100-by-100 Hough Array:
    (34,  1)
    (58,  1)
    (34,  2)
    (67, 20)
    (37, 42)
    (37, 43)
    (37, 44)
    (37, 45)
    (37, 46)
    (37, 47)
    (73, 72)
    (44, 87)
    (43, 89)
    (67, 89)
    (43, 90)
    (67, 90)
I put the origin at the center of edge map, So the original (rho, theta) values in edge map are shown below:
    （-57.5000，  2)
    （ 26.5000，  2)
    （-57.5000，  4)
    （ 58.0000， 40)
    （-47.0000， 84)
    （-47.0000， 86)
    （-47.0000， 88)
    （-47.0000， 90)
    （-47.0000， 92)
    （-47.0000， 94)
    （ 79.0000，144)
    （-22.5000，174)
    （-26.0000，178)
    （ 58.0000，178)
    （-26.0000，180)
    （ 58.0000，180)



    Tianyang Chen