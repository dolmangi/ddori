/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: E:\\dolproj\\2015_ddori\\src\\ddori\\src\\DaumTTS\\app\\src\\net\\daum\\speech\\api\\openapisample\\ITtsService.aidl
 */
package net.daum.speech.api.openapisample;
// Declare any non-default types here with import statements

public interface ITtsService extends android.os.IInterface
{
/** Local-side IPC implementation stub class. */
public static abstract class Stub extends android.os.Binder implements net.daum.speech.api.openapisample.ITtsService
{
private static final java.lang.String DESCRIPTOR = "net.daum.speech.api.openapisample.ITtsService";
/** Construct the stub at attach it to the interface. */
public Stub()
{
this.attachInterface(this, DESCRIPTOR);
}
/**
 * Cast an IBinder object into an net.daum.speech.api.openapisample.ITtsService interface,
 * generating a proxy if needed.
 */
public static net.daum.speech.api.openapisample.ITtsService asInterface(android.os.IBinder obj)
{
if ((obj==null)) {
return null;
}
android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
if (((iin!=null)&&(iin instanceof net.daum.speech.api.openapisample.ITtsService))) {
return ((net.daum.speech.api.openapisample.ITtsService)iin);
}
return new net.daum.speech.api.openapisample.ITtsService.Stub.Proxy(obj);
}
@Override public android.os.IBinder asBinder()
{
return this;
}
@Override public boolean onTransact(int code, android.os.Parcel data, android.os.Parcel reply, int flags) throws android.os.RemoteException
{
switch (code)
{
case INTERFACE_TRANSACTION:
{
reply.writeString(DESCRIPTOR);
return true;
}
case TRANSACTION_SetTts:
{
data.enforceInterface(DESCRIPTOR);
java.lang.String _arg0;
_arg0 = data.readString();
this.SetTts(_arg0);
reply.writeNoException();
return true;
}
}
return super.onTransact(code, data, reply, flags);
}
private static class Proxy implements net.daum.speech.api.openapisample.ITtsService
{
private android.os.IBinder mRemote;
Proxy(android.os.IBinder remote)
{
mRemote = remote;
}
@Override public android.os.IBinder asBinder()
{
return mRemote;
}
public java.lang.String getInterfaceDescriptor()
{
return DESCRIPTOR;
}
/**
     * Demonstrates some basic types that you can use as parameters
     * and return values in AIDL.
     */
@Override public void SetTts(java.lang.String ttstext) throws android.os.RemoteException
{
android.os.Parcel _data = android.os.Parcel.obtain();
android.os.Parcel _reply = android.os.Parcel.obtain();
try {
_data.writeInterfaceToken(DESCRIPTOR);
_data.writeString(ttstext);
mRemote.transact(Stub.TRANSACTION_SetTts, _data, _reply, 0);
_reply.readException();
}
finally {
_reply.recycle();
_data.recycle();
}
}
}
static final int TRANSACTION_SetTts = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
}
/**
     * Demonstrates some basic types that you can use as parameters
     * and return values in AIDL.
     */
public void SetTts(java.lang.String ttstext) throws android.os.RemoteException;
}
