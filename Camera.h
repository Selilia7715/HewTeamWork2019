#pragma once

#include <Windows.h>
#include <DirectXMath.h>
#include <cmath>
class Camera
{
public:
	Camera();

	//���������λ��
	void SetPosition(float x, float y, float z) { m_position = DirectX::XMFLOAT3(x, y, z); }
	void SetPosition(DirectX::FXMVECTOR pos) { DirectX::XMStoreFloat3(&m_position, pos); }

	//��������λ�÷������ز���
	DirectX::XMFLOAT3 GetPosition() const { return m_position; }
	DirectX::XMFLOAT3 GetRight() { return m_right; }
	DirectX::XMFLOAT3 GetLook() { return m_look; }
	DirectX::XMFLOAT3 GetUp() { return m_up; }

	DirectX::XMVECTOR GetPosotionXM() const { return DirectX::XMLoadFloat3(&m_position); }
	DirectX::XMVECTOR GetRightXM() const { return DirectX::XMLoadFloat3(&m_right); }
	DirectX::XMVECTOR GetLookXM() const { return DirectX::XMLoadFloat3(&m_look); }
	DirectX::XMVECTOR GetUpXM() const { return DirectX::XMLoadFloat3(&m_up); }

	//���ͶӰ��ز���
	float GetNearZ() const { return m_nearZ; }
	float GetFarZ() const { return m_farZ; }
	float GetFovY() const { return m_fovY; }
	float GetFovX() const { return atan(m_aspect * tan(m_fovY * 0.5f)) * 2.f; }
	float GetAspect() const { return m_aspect; }

	//�����ͼͶӰ��ՁE
	DirectX::XMMATRIX GetView() const { return DirectX::XMLoadFloat4x4(&m_view); }
	DirectX::XMMATRIX GetProj() const { return DirectX::XMLoadFloat4x4(&m_proj); }
	DirectX::XMMATRIX GetViewProj() const { return XMLoadFloat4x4(&m_view) * XMLoadFloat4x4(&m_proj); }

	//����ͶӰ��ՁE
	void SetLens(float fovY, float aspect, float nearz, float farz);

	//�����ӽǾ�ՁE
	void LookAtXM(DirectX::FXMVECTOR pos, DirectX::FXMVECTOR lookAt, DirectX::FXMVECTOR worldUp);
	void LookAt(const DirectX::XMFLOAT3& pos, const DirectX::XMFLOAT3& lookAt, 
		const DirectX::XMFLOAT3& worldUp);

	//������ׁE
	void Walk(float dist);			//ǰ������
	void Strafe(float dist);			//����ƽ��
	void Pitch(float angle);			//���µ�ͷ
	void RotateY(float angle);		//����ҡͷ

	//��E¾�ՁE
	void UpdateViewMatrix();
private:
	DirectX::XMFLOAT3 m_right;		//λ�ú���������E�E
	DirectX::XMFLOAT3 m_up;
	DirectX::XMFLOAT3 m_look;
	DirectX::XMFLOAT3 m_position;

	float m_aspect;					//ͶӰ��ز���
	float m_fovY;
	float m_nearZ;
	float m_farZ;

	DirectX::XMFLOAT4X4 m_view;		//�ӽǾ�ՁE
	DirectX::XMFLOAT4X4 m_proj;		//ͶӰ��ՁE
};