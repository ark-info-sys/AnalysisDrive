/**
 * @file   JsonValue.h
 * @brief  JSONの値
 * @author kyo
 * @date   2015/05/05
 */
#ifndef ANALYSISDRIVE_JSONVALUE_H_
#define ANALYSISDRIVE_JSONVALUE_H_

#include "Json.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <ostream>

#undef GetObject

/** Analysis Drive */
namespace adlib
{
/**
 * JSONの値
 * @remarks 抽象クラス
 */
class JsonValue
{
public:
  /** 仮想デストラクタ */
  virtual ~JsonValue() {}

  /**
   * 型を取得
   * @return 型
   */
  virtual Json::JSON_VALUE_TYPE GetValueType() const = 0;

  /**
   * string値のget
   * @return string値
   * @remarks オーバーライドされない場合の動作 <br>
   *          空文字""を返す
   */
  virtual const std::string& GetString() const;

  /**
   * number値(int)のget
   * @return number値(int)
   * @remarks オーバーライドされない場合の動作 <br>
   *          0を返す
   */
  virtual int GetNumberInt() const;

  /**
   * number値(double)のget
   * @return number値(double)
   * @remarks オーバーライドされない場合の動作 <br>
   *          0.0を返す
   */
  virtual double GetNumberDouble() const;

  /**
   * bool値のget
   * @return bool値
   * @remarks オーバーライドされない場合の動作 <br>
   *          falseを返す
   */
  virtual bool GetBool() const;

  /**
   * array値のget
   * @return array値
   * @remarks オーバーライドされない場合の動作 <br>
   *          空のvectorを返す
   */
  virtual Json::Array& GetArray();

  /**
   * array値のget(const版)
   * @return array値
   * @remarks オーバーライドされない場合の動作 <br>
   *          空のvectorを返す
   */
  virtual const Json::Array& GetArray() const;

  /**
   * object値のget
   * @return object値
   * @remarks オーバーライドされない場合の動作 <br>
   *          空のmapを返す
   */
  virtual Json::Object& GetObject();

  /**
   * object値のget(const版)
   * @return object値
   * @remarks オーバーライドされない場合の動作 <br>
   *          空のmapを返す
   */
  virtual const Json::Object& GetObject() const;

  /**
   * JSON形式の文字列を出力
   * @param[in,out] outStream 出力先のストリーム
   */
  virtual void Dump(std::ostream* outStream) const;

  /**
   * MessagePack形式のバイナリを出力
   * @param[in,out] outStream 出力先のストリーム
   */
  virtual void DumpMsgpack(std::ostream* outStream) const;
};
}
#endif // ANALYSISDRIVE_JSONVALUE_H_
