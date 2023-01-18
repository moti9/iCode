import addition
# import pytest

import unittest as uni

def test_add():
    assert addition.add(9, 6) == 15

    # uni.findTestCases


def test_sub():
    assert addition.sub(9, 6) == 3


def test_div():
    assert addition.div(0, 9) == 0
