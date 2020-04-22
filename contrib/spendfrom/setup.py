from distutils.core import setup
setup(name='sysspendfrom',
      version='1.0',
      description='Command-line utility for minerium "coin control"',
      author='Gavin Andresen',
      author_email='gavin@mineriumfoundation.org',
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )
