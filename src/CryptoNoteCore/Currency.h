// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <boost/utility.hpp>
#include "../CryptoNoteConfig.h"
#include "../crypto/hash.h"
#include "../Logging/LoggerRef.h"
#include "CachedBlock.h"
#include "CryptoNoteBasic.h"
#include "Difficulty.h"

namespace CryptoNote {

class AccountBase;

class Currency {
public:
  std::string cryptonoteName() const { return m_cryptonoteName; }
  uint32_t maxBlockHeight() const { return m_maxBlockHeight; }
  size_t maxBlockBlobSize() const { return m_maxBlockBlobSize; }
  size_t maxTxSize() const { return m_maxTxSize; }
  uint64_t publicAddressBase58Prefix() const { return m_publicAddressBase58Prefix; }
  uint32_t minedMoneyUnlockWindow() const { return m_minedMoneyUnlockWindow; }

  size_t timestampCheckWindow() const { return m_timestampCheckWindow; }
  uint64_t blockFutureTimeLimit() const { return m_blockFutureTimeLimit; }

  uint64_t moneySupply() const { return m_moneySupply; }
  unsigned int emissionSpeedFactor() const { return m_emissionSpeedFactor; }
  size_t cryptonoteCoinVersion() const { return m_cryptonoteCoinVersion; }
  uint64_t genesisBlockReward() const { return m_genesisBlockReward; }

  size_t rewardBlocksWindow() const { return m_rewardBlocksWindow; }
  size_t minMixin() const { return m_minMixin; }
  uint8_t mandatoryMixinBlockVersion() const { return m_mandatoryMixinBlockVersion; }
  uint32_t mixinStartHeight() const { return m_mixinStartHeight; }
  uint32_t mandatoryTransaction() const { return m_mandatoryTransaction; }
  uint32_t killHeight() const { return m_killHeight; }
  uint64_t tailEmissionReward() const { return m_tailEmissionReward; }
  uint32_t zawyDifficultyBlockIndex() const { return m_zawyDifficultyBlockIndex; }
  size_t zawyDifficultyV2() const { return m_zawyDifficultyV2; }
  uint8_t zawyDifficultyBlockVersion() const { return m_zawyDifficultyBlockVersion; }
  uint32_t buggedZawyDifficultyBlockIndex() const { return m_buggedZawyDifficultyBlockIndex; }
  size_t blockGrantedFullRewardZone() const { return m_blockGrantedFullRewardZone; }
  uint64_t expectedNumberOfBlocksPerDay() const { return m_expectedNumberOfBlocksPerDay; }
  size_t blockGrantedFullRewardZoneV1() const { return m_blockGrantedFullRewardZoneV1; }
  size_t blockGrantedFullRewardZoneV2() const { return m_blockGrantedFullRewardZoneV2; }
  uint32_t keyImageCheckingBlockIndex() const { return m_keyImageCheckingBlockIndex; }
  size_t blockGrantedFullRewardZoneByBlockVersion(uint8_t blockMajorVersion) const;
  size_t minerTxBlobReservedSize() const { return m_minerTxBlobReservedSize; }
  uint64_t maxTransactionSizeLimit() const { return m_maxTransactionSizeLimit; }

  size_t numberOfDecimalPlaces() const { return m_numberOfDecimalPlaces; }
  uint64_t coin() const { return m_coin; }

  uint64_t minimumFee() const { return m_mininumFee; }
  uint64_t defaultDustThreshold() const { return m_defaultDustThreshold; }

  uint64_t difficultyTarget() const { return m_difficultyTarget; }
  size_t difficultyWindow() const { return m_difficultyWindow; }
  size_t difficultyWindowV1() const { return m_difficultyWindowV1; }
  size_t difficultyWindowV2() const { return m_difficultyWindowV2; }
  size_t difficultyLagV1() const { return m_difficultyLagV1; }
  size_t difficultyLagV2() const { return m_difficultyLagV2; }
  size_t difficultyCutV1() const { return m_difficultyCutV1; }
  size_t difficultyCutV2() const { return m_difficultyCutV2; }
size_t difficultyWindowByBlockVersion(uint8_t blockMajorVersion) const;
  size_t difficultyLag() const { return m_difficultyLag; }
size_t difficultyLagByBlockVersion(uint8_t blockMajorVersion) const;
  size_t difficultyCut() const { return m_difficultyCut; }
size_t difficultyCutByBlockVersion(uint8_t blockMajorVersion) const;
  size_t difficultyBlocksCount() const { return m_difficultyWindow + m_difficultyLag; }
size_t difficultyBlocksCountByBlockVersion(uint8_t blockMajorVersion) const;

  size_t maxBlockSizeInitial() const { return m_maxBlockSizeInitial; }
  uint64_t maxBlockSizeGrowthSpeedNumerator() const { return m_maxBlockSizeGrowthSpeedNumerator; }
  uint64_t maxBlockSizeGrowthSpeedDenominator() const { return m_maxBlockSizeGrowthSpeedDenominator; }

  uint64_t lockedTxAllowedDeltaSeconds() const { return m_lockedTxAllowedDeltaSeconds; }
  size_t lockedTxAllowedDeltaBlocks() const { return m_lockedTxAllowedDeltaBlocks; }

  uint64_t mempoolTxLiveTime() const { return m_mempoolTxLiveTime; }
  uint64_t mempoolTxFromAltBlockLiveTime() const { return m_mempoolTxFromAltBlockLiveTime; }
  uint64_t numberOfPeriodsToForgetTxDeletedFromPool() const { return m_numberOfPeriodsToForgetTxDeletedFromPool; }

  size_t fusionTxMaxSize() const { return m_fusionTxMaxSize; }
  size_t fusionTxMinInputCount() const { return m_fusionTxMinInputCount; }
  size_t fusionTxMinInOutCountRatio() const { return m_fusionTxMinInOutCountRatio; }

  uint32_t upgradeHeight(uint8_t majorVersion) const;
  unsigned int upgradeVotingThreshold() const { return m_upgradeVotingThreshold; }
  uint32_t upgradeVotingWindow() const { return m_upgradeVotingWindow; }
  uint32_t upgradeWindow() const { return m_upgradeWindow; }
  uint32_t minNumberVotingBlocks() const { return (m_upgradeVotingWindow * m_upgradeVotingThreshold + 99) / 100; }
  uint32_t maxUpgradeDistance() const { return 7 * m_upgradeWindow; }
  uint32_t calculateUpgradeHeight(uint32_t voteCompleteHeight) const { return voteCompleteHeight + m_upgradeWindow; }

  const std::string& blocksFileName() const { return m_blocksFileName; }
  const std::string& blockIndexesFileName() const { return m_blockIndexesFileName; }
  const std::string& txPoolFileName() const { return m_txPoolFileName; }

  bool isBlockexplorer() const { return m_isBlockexplorer; }
  bool isTestnet() const { return m_testnet; }

  const BlockTemplate& genesisBlock() const { return cachedGenesisBlock->getBlock(); }
  const Crypto::Hash& genesisBlockHash() const { return cachedGenesisBlock->getBlockHash(); }

  bool getBlockReward(uint8_t blockMajorVersion, size_t medianSize, size_t currentBlockSize, uint64_t alreadyGeneratedCoins, uint64_t fee,
    uint64_t& reward, int64_t& emissionChange) const;
  size_t maxBlockCumulativeSize(uint64_t height) const;

  bool constructMinerTx(uint8_t blockMajorVersion, uint32_t height, size_t medianSize, uint64_t alreadyGeneratedCoins, size_t currentBlockSize,
    uint64_t fee, const AccountPublicAddress& minerAddress, Transaction& tx, const BinaryArray& extraNonce = BinaryArray(), size_t maxOuts = 1) const;

  bool isFusionTransaction(const Transaction& transaction) const;
  bool isFusionTransaction(const Transaction& transaction, size_t size) const;
  bool isFusionTransaction(const std::vector<uint64_t>& inputsAmounts, const std::vector<uint64_t>& outputsAmounts, size_t size) const;
  bool isAmountApplicableInFusionTransactionInput(uint64_t amount, uint64_t threshold) const;
  bool isAmountApplicableInFusionTransactionInput(uint64_t amount, uint64_t threshold, uint8_t& amountPowerOfTen) const;

  std::string accountAddressAsString(const AccountBase& account) const;
  std::string accountAddressAsString(const AccountPublicAddress& accountPublicAddress) const;
  bool parseAccountAddressString(const std::string& str, AccountPublicAddress& addr) const;

  std::string formatAmount(uint64_t amount) const;
  std::string formatAmount(int64_t amount) const;
  bool parseAmount(const std::string& str, uint64_t& amount) const;

  Difficulty nextDifficulty(std::vector<uint64_t> timestamps, std::vector<Difficulty> cumulativeDifficulties) const;
Difficulty nextDifficulty(uint8_t version, uint32_t blockIndex, std::vector<uint64_t> timestamps, std::vector<Difficulty> cumulativeDifficulties) const;

  bool checkProofOfWorkV1(Crypto::cn_context& context, const CachedBlock& block, Difficulty currentDifficulty) const;
  bool checkProofOfWorkV2(Crypto::cn_context& context, const CachedBlock& block, Difficulty currentDifficulty) const;
  bool checkProofOfWork(Crypto::cn_context& context, const CachedBlock& block, Difficulty currentDifficulty) const;

  Currency(Currency&& currency);

  size_t getApproximateMaximumInputCount(size_t transactionSize, size_t outputCount, size_t mixinCount) const;

private:
  Currency(Logging::ILogger& log) : logger(log, "currency") {
  }

  bool init();

  bool generateGenesisBlock();

private:
  std::string m_cryptonoteName;
  uint32_t m_maxBlockHeight;
  size_t m_maxBlockBlobSize;
  size_t m_maxTxSize;
  uint64_t m_publicAddressBase58Prefix;
  uint32_t m_minedMoneyUnlockWindow;

  size_t m_timestampCheckWindow;
  uint64_t m_blockFutureTimeLimit;

  uint64_t m_moneySupply;
  unsigned int m_emissionSpeedFactor;
  size_t m_cryptonoteCoinVersion;
  uint64_t m_genesisBlockReward;

  size_t m_rewardBlocksWindow;
  size_t m_minMixin;
  uint8_t m_mandatoryMixinBlockVersion;
  uint32_t m_mixinStartHeight;
  uint32_t m_mandatoryTransaction;
  uint32_t m_killHeight;
  uint64_t m_tailEmissionReward;
  uint32_t m_zawyDifficultyBlockIndex;
  size_t m_zawyDifficultyV2;
  uint8_t m_zawyDifficultyBlockVersion;
  uint32_t m_buggedZawyDifficultyBlockIndex;
  size_t m_blockGrantedFullRewardZone;
  uint64_t m_expectedNumberOfBlocksPerDay;
  size_t m_blockGrantedFullRewardZoneV1;
  size_t m_blockGrantedFullRewardZoneV2;
  uint32_t m_keyImageCheckingBlockIndex;
  size_t m_minerTxBlobReservedSize;
  uint64_t m_maxTransactionSizeLimit;

  size_t m_numberOfDecimalPlaces;
  uint64_t m_coin;

  uint64_t m_mininumFee;
  uint64_t m_defaultDustThreshold;

  uint64_t m_difficultyTarget;
  size_t m_difficultyWindowV1;
  size_t m_difficultyWindowV2;
  size_t m_difficultyLagV1;
  size_t m_difficultyLagV2;
  size_t m_difficultyCutV1;
  size_t m_difficultyCutV2;
  size_t m_difficultyWindow;
  size_t m_difficultyLag;
  size_t m_difficultyCut;

  size_t m_maxBlockSizeInitial;
  uint64_t m_maxBlockSizeGrowthSpeedNumerator;
  uint64_t m_maxBlockSizeGrowthSpeedDenominator;

  uint64_t m_lockedTxAllowedDeltaSeconds;
  size_t m_lockedTxAllowedDeltaBlocks;

  uint64_t m_mempoolTxLiveTime;
  uint64_t m_mempoolTxFromAltBlockLiveTime;
  uint64_t m_numberOfPeriodsToForgetTxDeletedFromPool;

  size_t m_fusionTxMaxSize;
  size_t m_fusionTxMinInputCount;
  size_t m_fusionTxMinInOutCountRatio;

  uint32_t m_upgradeHeightV2;
  uint32_t m_upgradeHeightV3;
  unsigned int m_upgradeVotingThreshold;
  uint32_t m_upgradeVotingWindow;
  uint32_t m_upgradeWindow;

  std::string m_blocksFileName;
  std::string m_blockIndexesFileName;
  std::string m_txPoolFileName;

  static const std::vector<uint64_t> PRETTY_AMOUNTS;

  bool m_testnet;
  std::string m_genesisCoinbaseTxHex;
  bool m_isBlockexplorer;

  BlockTemplate genesisBlockTemplate;
  std::unique_ptr<CachedBlock> cachedGenesisBlock;

  Logging::LoggerRef logger;

  friend class CurrencyBuilder;
};

class CurrencyBuilder : boost::noncopyable {
public:
  CurrencyBuilder(Logging::ILogger& log);

  Currency currency() {
    if (!m_currency.init()) {
      throw std::runtime_error("Failed to initialize currency object");
    }

    return std::move(m_currency);
  }

  Transaction generateGenesisTransaction();
  Transaction generateGenesisTransaction(const std::vector<AccountPublicAddress>& targets);
  CurrencyBuilder& cryptonoteName(std::string val) { m_currency.m_cryptonoteName = val; return *this; }
  CurrencyBuilder& maxBlockNumber(uint32_t val) { m_currency.m_maxBlockHeight = val; return *this; }
  CurrencyBuilder& maxBlockBlobSize(size_t val) { m_currency.m_maxBlockBlobSize = val; return *this; }
  CurrencyBuilder& maxTxSize(size_t val) { m_currency.m_maxTxSize = val; return *this; }
  CurrencyBuilder& publicAddressBase58Prefix(uint64_t val) { m_currency.m_publicAddressBase58Prefix = val; return *this; }
  CurrencyBuilder& minedMoneyUnlockWindow(uint32_t val) { m_currency.m_minedMoneyUnlockWindow = val; return *this; }

  CurrencyBuilder& timestampCheckWindow(size_t val) { m_currency.m_timestampCheckWindow = val; return *this; }
  CurrencyBuilder& blockFutureTimeLimit(uint64_t val) { m_currency.m_blockFutureTimeLimit = val; return *this; }

  CurrencyBuilder& moneySupply(uint64_t val) { m_currency.m_moneySupply = val; return *this; }
  CurrencyBuilder& emissionSpeedFactor(unsigned int val);
  CurrencyBuilder& cryptonoteCoinVersion(size_t val) { m_currency.m_cryptonoteCoinVersion = val; return *this; }
  CurrencyBuilder& genesisBlockReward(uint64_t val) { m_currency.m_genesisBlockReward = val; return *this; }

  CurrencyBuilder& rewardBlocksWindow(size_t val) { m_currency.m_rewardBlocksWindow = val; return *this; }
  CurrencyBuilder& minMixin(size_t val) { m_currency.m_minMixin = val; return *this; }
  CurrencyBuilder& mandatoryMixinBlockVersion(uint8_t val) { m_currency.m_mandatoryMixinBlockVersion = val; return *this; }
  CurrencyBuilder& mixinStartHeight(uint32_t val) { m_currency.m_mixinStartHeight = val; return *this; }
  CurrencyBuilder& mandatoryTransaction(uint8_t val) { m_currency.m_mandatoryTransaction = val; return *this; }
  CurrencyBuilder& killHeight(uint32_t val) { m_currency.m_killHeight = val; return *this; }
  CurrencyBuilder& tailEmissionReward(uint64_t val) { m_currency.m_tailEmissionReward = val; return *this; }
  CurrencyBuilder& zawyDifficultyBlockIndex(uint32_t val) { m_currency.m_zawyDifficultyBlockIndex = val; return *this; }
  CurrencyBuilder& zawyDifficultyV2(size_t val) { m_currency.m_zawyDifficultyV2 = val; return *this; }
  CurrencyBuilder& zawyDifficultyBlockVersion(uint8_t val) { m_currency.m_zawyDifficultyBlockVersion = val; return *this; }
  CurrencyBuilder& buggedZawyDifficultyBlockIndex(uint32_t val) { m_currency.m_buggedZawyDifficultyBlockIndex = val; return *this; }
  CurrencyBuilder& blockGrantedFullRewardZone(size_t val) { m_currency.m_blockGrantedFullRewardZone = val; return *this; }
  CurrencyBuilder& expectedNumberOfBlocksPerDay(uint64_t val) { m_currency.m_expectedNumberOfBlocksPerDay = val; return *this; }
  CurrencyBuilder& blockGrantedFullRewardZoneV1(size_t val) { m_currency.m_blockGrantedFullRewardZoneV1 = val; return *this; }
  CurrencyBuilder& blockGrantedFullRewardZoneV2(size_t val) { m_currency.m_blockGrantedFullRewardZoneV2 = val; return *this; }
  CurrencyBuilder& keyImageCheckingBlockIndex(uint32_t val) { m_currency.m_keyImageCheckingBlockIndex = val; return *this; }
  CurrencyBuilder& minerTxBlobReservedSize(size_t val) { m_currency.m_minerTxBlobReservedSize = val; return *this; }
  CurrencyBuilder& maxTransactionSizeLimit(uint64_t val) { m_currency.m_maxTransactionSizeLimit = val; return *this; }

  CurrencyBuilder& numberOfDecimalPlaces(size_t val);

  CurrencyBuilder& mininumFee(uint64_t val) { m_currency.m_mininumFee = val; return *this; }
  CurrencyBuilder& defaultDustThreshold(uint64_t val) { m_currency.m_defaultDustThreshold = val; return *this; }

  CurrencyBuilder& difficultyTarget(uint64_t val) { m_currency.m_difficultyTarget = val; return *this; }
  CurrencyBuilder& difficultyWindowV1(size_t val) { m_currency.m_difficultyWindowV1 = val; return *this; }
  CurrencyBuilder& difficultyWindowV2(size_t val) { m_currency.m_difficultyWindowV2 = val; return *this; }
  CurrencyBuilder& difficultyLagV1(size_t val) { m_currency.m_difficultyLagV1 = val; return *this; }
  CurrencyBuilder& difficultyLagV2(size_t val) { m_currency.m_difficultyLagV2 = val; return *this; }
  CurrencyBuilder& difficultyCutV1(size_t val) { m_currency.m_difficultyCutV1 = val; return *this; }
  CurrencyBuilder& difficultyCutV2(size_t val) { m_currency.m_difficultyCutV2 = val; return *this; }
  CurrencyBuilder& difficultyWindow(size_t val);
  CurrencyBuilder& difficultyLag(size_t val) { m_currency.m_difficultyLag = val; return *this; }
  CurrencyBuilder& difficultyCut(size_t val) { m_currency.m_difficultyCut = val; return *this; }

  CurrencyBuilder& maxBlockSizeInitial(size_t val) { m_currency.m_maxBlockSizeInitial = val; return *this; }
  CurrencyBuilder& maxBlockSizeGrowthSpeedNumerator(uint64_t val) { m_currency.m_maxBlockSizeGrowthSpeedNumerator = val; return *this; }
  CurrencyBuilder& maxBlockSizeGrowthSpeedDenominator(uint64_t val) { m_currency.m_maxBlockSizeGrowthSpeedDenominator = val; return *this; }

  CurrencyBuilder& lockedTxAllowedDeltaSeconds(uint64_t val) { m_currency.m_lockedTxAllowedDeltaSeconds = val; return *this; }
  CurrencyBuilder& lockedTxAllowedDeltaBlocks(size_t val) { m_currency.m_lockedTxAllowedDeltaBlocks = val; return *this; }

  CurrencyBuilder& mempoolTxLiveTime(uint64_t val) { m_currency.m_mempoolTxLiveTime = val; return *this; }
  CurrencyBuilder& mempoolTxFromAltBlockLiveTime(uint64_t val) { m_currency.m_mempoolTxFromAltBlockLiveTime = val; return *this; }
  CurrencyBuilder& numberOfPeriodsToForgetTxDeletedFromPool(uint64_t val) { m_currency.m_numberOfPeriodsToForgetTxDeletedFromPool = val; return *this; }

  CurrencyBuilder& fusionTxMaxSize(size_t val) { m_currency.m_fusionTxMaxSize = val; return *this; }
  CurrencyBuilder& fusionTxMinInputCount(size_t val) { m_currency.m_fusionTxMinInputCount = val; return *this; }
  CurrencyBuilder& fusionTxMinInOutCountRatio(size_t val) { m_currency.m_fusionTxMinInOutCountRatio = val; return *this; }

  CurrencyBuilder& upgradeHeightV2(uint32_t val) { m_currency.m_upgradeHeightV2 = val; return *this; }
  CurrencyBuilder& upgradeHeightV3(uint32_t val) { m_currency.m_upgradeHeightV3 = val; return *this; }
  CurrencyBuilder& upgradeVotingThreshold(unsigned int val);
  CurrencyBuilder& upgradeVotingWindow(uint32_t val) { m_currency.m_upgradeVotingWindow = val; return *this; }
  CurrencyBuilder& upgradeWindow(uint32_t val);

  CurrencyBuilder& blocksFileName(const std::string& val) { m_currency.m_blocksFileName = val; return *this; }
  CurrencyBuilder& blockIndexesFileName(const std::string& val) { m_currency.m_blockIndexesFileName = val; return *this; }
  CurrencyBuilder& txPoolFileName(const std::string& val) { m_currency.m_txPoolFileName = val; return *this; }
  
  CurrencyBuilder& isBlockexplorer(const bool val) { m_currency.m_isBlockexplorer = val; return *this; }
  CurrencyBuilder& genesisCoinbaseTxHex(const std::string& val) { m_currency.m_genesisCoinbaseTxHex = val; return *this; }
  CurrencyBuilder& testnet(bool val) { m_currency.m_testnet = val; return *this; }

private:
  Currency m_currency;
};

}
