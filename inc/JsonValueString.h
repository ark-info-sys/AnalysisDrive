/**
 * @file   JsonValueString.h
 * @brief  JSONの値(string)
 * @author kyo
 * @date   2015/05/05
 */
#ifndef ANALYSISDRIVE_JSONVALUESTRING_H_
#define ANALYSISDRIVE_JSONVALUESTRING_H_

#include "JsonValue.h"
#include "Json.h"
#include "IncludeMsgpack.h"
#include <string>

/** Analysis Drive */
namespace adlib
{
/** JSONの値(string) */
class JsonValueString final : public JsonValue
{
private:
  //! 値
  std::string m_value;

private:
  /** デフォルトコンストラクタ禁止 */
  JsonValueString() {}
  /** コピー禁止 */
  JsonValueString(const JsonValueString&);
  /** 代入禁止 */
  void operator=(const JsonValueString&);

public:
  /**
   * コンストラクタ
   * @tparam value 値
   */
  explicit JsonValueString(const std::string& value) : m_value(value) {}

  /** 仮想デストラクタ */
  virtual ~JsonValueString() {}

  /**
   * 型を取得
   * @return 型
   */
  Json::JSON_VALUE_TYPE GetValueType() const override
  {
    return Json::JSON_VALUE_TYPE::STRING;
  }

  /**
   * string値のget
   * @return string値
   */
  const std::string& GetString() const override
  {
    return m_value;
  }

  /**
   * JSON形式の文字列を出力
   * @param[in,out] outStream 出力先のストリーム
   */
  void Dump(std::ostream* outStream) const override
  {
    *outStream << "\"" << m_value << "\"" << std::flush;
  }

  /**
   * MessagePack形式のバイナリを出力
   * @param[in,out] outStream 出力先のストリーム
   */
  void DumpMsgpack(std::ostream* outStream) const override
  {
    msgpack::pack(outStream, m_value);
  }
};
}
#endif // ANALYSISDRIVE_JSONVALUESTRING_H_
