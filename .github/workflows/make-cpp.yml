name: C/C++ CI

on:
  push:
    branches: [ main ]
  pull_request:
    branches: [ main ]

jobs:
  build:

    runs-on: ubuntu-latest

    steps:
    - uses: actions/checkout@v2
    - name: configure
      run: ./configure
    - name: make
      run: Implementation_main_c.c
    - name: make check
      run: Implementation_main_c.c
    - name: make distcheck
      run: Implementation_main_c.c
