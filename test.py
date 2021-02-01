# TODO: optimize file pathing in TestFileEnvironment for different platforms.
from scripttest import TestFileEnvironment
import filecmp
import os

env = TestFileEnvironment('./scratch')

def synthetic():
    env.clear()

    print('Testing input 12 3 21')
    encode_result_0 = env.run('..\\ant', '12', '3', '21', expect_error = False)
    assert encode_result_0.returncode == 0;
    assert encode_result_0.stdout.startswith('72469')
    print('OK')

    print('Testing input 67 12 19')
    encode_result_0 = env.run('..\\ant', '67', '12', '19', expect_error = False)
    assert encode_result_0.returncode == 0;
    assert encode_result_0.stdout.startswith('25920')
    print('OK')

    print('Testing input 137 67 25')
    encode_result_0 = env.run('..\\ant', '137', '67', '25', expect_error = False)
    assert encode_result_0.returncode == 0;
    assert encode_result_0.stdout.startswith('259359')
    print('OK')

    print('Testing input 15 653 25')
    encode_result_0 = env.run('..\\ant', '15', '653', '25', expect_error = False)
    assert encode_result_0.returncode == 0;
    assert encode_result_0.stdout.startswith('259359')
    print('OK')

    print('Testing input 1000 1000 25')
    encode_result_0 = env.run('..\\ant', '1000', '1000', '25', expect_error = False)
    assert encode_result_0.returncode == 0;
    assert encode_result_0.stdout.startswith('148848')
    print('OK')

    print('All tests with synthetic data are passed')


if __name__ == "__main__":
    synthetic()
    print('All tests are passed')