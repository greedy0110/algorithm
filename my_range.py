class MyRange:
    # start, stop, step 을 인자로 받는다.
    def __init__(self, start, stop, step=1):
        self._start = start
        self._stop = stop
        self._step = step

        self._current = start - step

    # __next__, __iter__ 를 구현해야 한다.
    def __next__(self):
        self._current += self._step
        if self._current < self._stop:
            return self._current
        else:
            raise StopIteration()

    def __iter__(self):
        return self

    # __len__, __getitem__ 을 구현해야 한다.
    def __len__(self):
        return max(0, (self._stop - self._start + self._step - 1) // self._step)
