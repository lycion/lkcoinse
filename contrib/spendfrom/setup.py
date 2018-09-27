from distutils.core import setup
setup(name='lcsspendfrom',
      version='1.0',
      description='Command-line utility for lkcoinse "coin control"',
      author='Gavin Andresen',
      author_email='gavin@lkcoinsefoundation.org',
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )
