# big 1, medium 2, small 3
class ParkingSystem:

    def __init__(self, big: int, medium: int, small: int):
        self.parking_lots = [big, medium, small]

    def addCar(self, carType: int) -> bool:
        if self.parking_lots[carType-1] > 0:
            self.parking_lots[carType-1] -= 1
            return True
        else:
            return False
