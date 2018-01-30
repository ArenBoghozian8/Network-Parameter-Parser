# -*- Mode: python; py-indent-offset: 4; indent-tabs-mode: nil; coding: utf-8; -*-

# def options(opt):
#     pass

# def configure(conf):
#     conf.check_nonfatal(header_name='stdint.h', define_name='HAVE_STDINT_H')

def build(bld):
    module = bld.create_ns3_module('mahdi', ['core'])
    module.source = [
        'helper/mahdi-helper.cc',
        'model/ACL.cpp',
        'model/ACLEntry.cpp',
        'model/CLASS.cpp',
        'model/DiffServQueueBaseClass.cpp',
        'model/xmlread.cpp',
        'model/textRead.cpp',
        ]

    module_test = bld.create_ns3_module_test_library('mahdi')
    module_test.source = [
        'test/mahdi-test-suite.cc',
        ]

    headers = bld(features='ns3header')
    headers.module = 'mahdi'
    headers.source = [
        'helper/mahdi-helper.h',
        'model/ACL.h',
        'model/ACLEntry.h',
        'model/CLASS.h',
        'model/DiffServQueueBaseClass.h',
        'model/xmlread.h',
        'model/textRead.h',
        ]

    if bld.env.ENABLE_EXAMPLES:
        bld.recurse('examples')

    # bld.ns3_python_bindings()

