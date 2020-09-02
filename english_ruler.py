def draw_line(tick, label=''):
    print(tick * '-' + ' ' + label)


def draw_interval(tick):
    if tick > 0:
        draw_interval(tick-1)
        draw_line(tick)
        draw_interval(tick-1)


def draw_ruler(tick, length):
    draw_line(tick, '0')
    for j in range(length):
        draw_interval(tick-1)
        draw_line(tick, str(j+1))


draw_ruler(4, 2)
