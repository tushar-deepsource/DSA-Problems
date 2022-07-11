import sys


class rectangle:

    def __init__(self):
        self.x1, self.y1, self.x2, self.y2 = map(int, input().split())

    def area(self):
        return (self.x2 - self.x1) * (self.y2 - self.y1)


def intersectedArea(r1, r2):
    width = max(0, min(r1.x2, r2.x2) - max(r1.x1, r2.x1))
    height = max(0, min(r1.y2, r2.y2) - max(r1.y1, r2.y1))
    return height * width


sys.stdin = open("billboard.in", "r")
sys.stdout = open("billboard.out", "w")

rectangles = []
for _ in range(3):
    rectangles.append(rectangle())

print(rectangles[0].area() + rectangles[1].area() -
      intersectedArea(rectangles[0], rectangles[2]) -
      intersectedArea(rectangles[1], rectangles[2]))
