# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: util.proto

from google.protobuf.internal import enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='util.proto',
  package='util',
  syntax='proto2',
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\nutil.proto\x12\x04util*6\n\tMsgStatus\x12\r\n\tSTATUS_OK\x10\x00\x12\x1a\n\x16STATUS_UNKNOWN_MESSAGE\x10\x01'
)

_MSGSTATUS = _descriptor.EnumDescriptor(
  name='MsgStatus',
  full_name='util.MsgStatus',
  filename=None,
  file=DESCRIPTOR,
  create_key=_descriptor._internal_create_key,
  values=[
    _descriptor.EnumValueDescriptor(
      name='STATUS_OK', index=0, number=0,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='STATUS_UNKNOWN_MESSAGE', index=1, number=1,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=20,
  serialized_end=74,
)
_sym_db.RegisterEnumDescriptor(_MSGSTATUS)

MsgStatus = enum_type_wrapper.EnumTypeWrapper(_MSGSTATUS)
STATUS_OK = 0
STATUS_UNKNOWN_MESSAGE = 1


DESCRIPTOR.enum_types_by_name['MsgStatus'] = _MSGSTATUS
_sym_db.RegisterFileDescriptor(DESCRIPTOR)


# @@protoc_insertion_point(module_scope)