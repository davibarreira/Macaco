import setuptools

setuptools.setup(
        name = 'Macaco',
        verision = '0.0.1',
        description = 'Macaco - dataframe em c++',
        packages = setuptools.find_packages(),
        install_requires=[
                           'matplotlib',
                           'tabulate'
                        ]
    )
